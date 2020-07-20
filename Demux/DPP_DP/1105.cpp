// https://leetcode.com/problems/filling-bookcase-shelves/

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        // dp[i] = min height to place [i,n-1] books
        // dp[i] = i+1<= j <=n min(maxHeight[i,j-1]+dp[j])
        
        int n = books.size(), height, width;
        vector<int> dp(n+1, 10e6);
        
        // base case
        dp[n] = 0;
        
        for(int i = n-1; i>=0; i--){
            height = books[i][1];
            width = books[i][0];
            for(int j = i+1; j<=n and width<=shelf_width; j++){
                dp[i] = min(dp[i], height+dp[j]);
                if(j == n) continue;
                height = max(height, books[j][1]);
                width += books[j][0];
            }
        }
        return dp[0];
    }
};