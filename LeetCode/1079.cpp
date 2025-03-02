// https://leetcode.com/problems/letter-tile-possibilities/

// Method 1 (Backtracking, O(n!)):

class Solution {
    void helper(int index, unordered_map<char, int> & freq, char prev, int & count){
        for(auto & entry:freq){
            char cur = entry.first;
            if(cur == prev){
                continue;
            }
            for(int i=1; i<=entry.second; i++){
                freq[cur] -= i;
                count++;
                helper(index+i, freq, cur, count);
                freq[cur] += i;
            }
        }
    }
public:
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> freq;
        for(char c:tiles){
            freq[c]++;
        }
        int count = 0;
        helper(0, freq, 0, count);
        return count;
    }
};
