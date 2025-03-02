// https://leetcode.com/problems/count-the-number-of-consistent-strings/

// Method 1 (Hash tables, O(m + n*k)):

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> allowed_set(allowed.begin(), allowed.end());
        int consistentCount = 0;
        for(string & word: words){
            bool consistent = true;
            for(char c:word){
                if(allowed_set.count(c) == 0){
                    consistent = false;
                    break;
                }
            }
            if(consistent){
                consistentCount++;
            }
        }

        return consistentCount;
    }
};
