// https://leetcode.com/problems/distribute-candies-to-people/

// Method 1 (Maths, O(n)):

class Solution {
public:
    vector<int> distributeCandies(int candies, int n) {
        int rowSum = (n*(n+1))/2, completeRows, cur;
        // candies = min(candies, n*(2*n+1));
        vector<int> ans(n, 0);
        
        // last = last entry int the last completed row
        int last = sqrt(2*candies);
        if((last*(last+1))/2 > candies) last--;
        completeRows = last/n;
        candies -= (((completeRows*n)*(completeRows*n+1))/2);
        
        for(int i = 0; i<n; i++){
            if(completeRows) ans[i] += (((i+1)*completeRows)+n*(((completeRows-1)*completeRows)/2));
            if(candies>0) {
                cur = min(candies, (n*completeRows+i+1));
                ans[i] += cur;
                candies -= cur;
            }
        }
        return ans;
    }
};