// https://leetcode.com/problems/word-subsets/

// Method 1 (Vectors, O(n+m)):

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> targetFreq(26);
        for(const string & word:words2){
            vector<int> freq(26);
            for(const char c:word){
                freq[c-'a']++;
            }
            for(int i=0; i<26; i++){
                targetFreq[i] = max(targetFreq[i], freq[i]);
            }
        }

        vector<string> res;
        for(const string & word:words1){
            vector<int> freq(26);
            for(const char c:word){
                freq[c-'a']++;
            }

            bool isUniversal = true;
            for(int i=0; i<26; i++){
                if(freq[i] < targetFreq[i]){
                    isUniversal = false;
                    break;
                }
            }
            if(isUniversal){
                res.push_back(word);
            }
        }

        return res;
    }
};

// Alternate Code:

class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int> max_freq_b(26, 0);
        for(auto i:B){
            vector<int> freq_b(26, 0);
            for(auto j:i){
                freq_b[j-'a']++;
            }
            for(int j = 0; j<26; j++){
                max_freq_b[j] = max(max_freq_b[j], freq_b[j]);
            }
        }
        
        vector<string> ans;
        
        for(auto i:A){
            vector<int> freq_a(26, 0);
            for(auto j:i){
                freq_a[j-'a']++;
            }
            int flag = 0;
            for(int j = 0; j<26; j++){
                if(max_freq_b[j] > freq_a[j]){
                    flag = 1;
                    break;
                }
            }
            if(!flag) ans.push_back(i);
        }
        return ans;
    }
};

// Method 2 (Hash Maps, O(n+m))

class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        unordered_map<char, int> freq;
        for(auto i:B){
            unordered_map<char, int> temp;
            for(auto j:i){
                temp[j]++;
            }
            for(auto j:temp){
                freq[j.first] = max(freq[j.first], j.second);
            }
        }
        
        vector<string> ans;
        
        for(auto i:A){
            unordered_map<char, int> temp;
            for(auto j:i){
                temp[j]++;
            }
            int flag = 0;
            for(auto j:freq){
                if(j.second > temp[j.first]){
                    flag = 1;
                    break;
                }
            }
            if(!flag) ans.push_back(i);
        }
        return ans;
    }
};