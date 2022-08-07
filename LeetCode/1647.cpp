// https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/

// Method 1 (Hash Map, Greedy, O(n)):

class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26, 0);
        for(auto &c:s){
            freq[c-'a']++;
        }
        unordered_map<int, int> freqFreq;
        for(auto &f:freq){
            freqFreq[f]++;
        }
        int deletions = 0;
        for(auto f:freq){
            while(f and freqFreq[f]>1){
                freqFreq[f]--;
                f--;
                deletions++;
                freqFreq[f]++;
            }
        }
        return deletions;
    }
};