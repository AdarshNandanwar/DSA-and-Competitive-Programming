// https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/

// Method 1 (Backtracking, O(2^n)):

class Solution {
    void helper(const string & s, int index, string & cur, unordered_set<string> & splits, int & maxSplits){
        int n = s.length();
        if(index == n){
            if(cur.length() == 0){
                maxSplits = max(maxSplits, (int)splits.size());
            }
            return;
        }

        cur.push_back(s[index]);
        if(splits.count(cur) == 0){
            splits.insert(cur);
            string next = "";
            helper(s, index+1, next, splits, maxSplits);
            splits.erase(cur);
        }
        helper(s, index+1, cur, splits, maxSplits);
        cur.pop_back();
    }
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> splits;
        string cur = "";
        int maxSplits = 0;
        helper(s, 0, cur, splits, maxSplits);
        return maxSplits;
    }
};
