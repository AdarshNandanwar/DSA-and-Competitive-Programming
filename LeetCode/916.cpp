// https://leetcode.com/problems/word-subsets/

// Method 1 (vectors)

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

// Method 2 (Hash Maps)

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