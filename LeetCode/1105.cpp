// https://leetcode.com/problems/filling-bookcase-shelves/

// Method 1 (1D DP, O(n * shelfWidth) time, O(n) space):

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        
        // dp[i] = min height of stacking books[i..n)
        vector<int> dp(n+1, INT_MAX);
        dp[n] = 0;
        for(int i=n-1; i>=0; i--){
            int shelfBooksWidth = 0;
            int shelfBooksHeight = 0;
            for(int j=i; j<n; j++){
                shelfBooksWidth += books[j][0];
                shelfBooksHeight = max(shelfBooksHeight, books[j][1]);
                if(shelfBooksWidth > shelfWidth){
                    break;
                }
                dp[i] = min(dp[i], shelfBooksHeight + dp[j+1]);
            }
        }

        return dp[0];
    }
};
