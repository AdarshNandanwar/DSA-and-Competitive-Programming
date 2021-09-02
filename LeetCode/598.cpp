// https://leetcode.com/problems/range-addition-ii/

// Method 1 (O(ops.length())):

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int a = m, b = n;
        for(auto &o:ops){
            a = min(a, o[0]);
            b = min(b, o[1]);
        }
        return a*b;
    }
};