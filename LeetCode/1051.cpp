// https://leetcode.com/problems/height-checker/

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> sh(heights.begin(), heights.end());
        sort(sh.begin(), sh.end());
        int count = 0;
        for(int i = 0; i<sh.size(); i++) count += (sh[i]!=heights[i]);
        return count;
    }
};