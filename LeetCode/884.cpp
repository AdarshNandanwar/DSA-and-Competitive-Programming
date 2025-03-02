// https://leetcode.com/problems/uncommon-words-from-two-sentences/

// Method 1 (Hash Map, String Stream, O(n)):

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> ans;
        
        unordered_map<string, int> freq;
        string word;
        istringstream iss1(s1);
        while(getline(iss1, word, ' ')){
            freq[word]++;
        }
        istringstream iss2(s2);
        while(getline(iss2, word, ' ')){
            freq[word]++;
        }

        for(auto entry:freq){
            if(entry.second == 1){
                ans.push_back(entry.first);
            }
        }

        return ans;
    }
};
