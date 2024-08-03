// https://leetcode.com/problems/find-common-characters/

// Method 1 (Counting, O(n)):

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> commonFreq(26, 100);
        
        for(const string & word:words){
            vector<int> freq(26, 0);
            for(char c:word){
                freq[c-'a']++;
            }
            for(int i=0; i<26; i++){
                commonFreq[i] = min(commonFreq[i], freq[i]);
            }
        }

        vector<string> ans;
        for(int i=0; i<26; i++){
            for(int j=0; j<commonFreq[i]; j++){
                ans.push_back(string(1, i+'a'));
            }
        }
        return ans;
    }
};
