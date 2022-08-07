// https://leetcode.com/problems/count-vowels-permutation/

// Method 1 (2D DP, O(n)):

#define MOD 1000000007

class Solution {
public:
    int countVowelPermutation(int n) {
        // dp[i][j] = number of permutations of length i starting with j
        vector<vector<int>> validSuccessor{
            {1},
            {0, 2},
            {0, 1, 3, 4},
            {2, 4},
            {0}
        };
        vector<vector<int>> dp(n+1, vector<int>(5, 0));
        for(int i=0; i<5; i++){
            dp[1][i] = 1;
        }        
        for(int i=2; i<=n; i++){
            for(int j=0; j<5; j++){
                for(auto &k:validSuccessor[j]){
                    dp[i][j] = (dp[i][j]+dp[i-1][k])%MOD;
                }
            }
        }
        int count = 0;
        for(auto &i:dp[n]){
            count = (count+i)%MOD;
        }
        return count;
    }
};

// Alternate Code:

#define MOD 1000000007

class Solution {
public:
    int countVowelPermutation(int n) {
        // a => 0;
        // e => 1;
        // r => 2;
        // o => 3;
        // u => 4;
        vector<vector<long long>> dp(n+1, vector<long long>(5));
        dp[1] = {1,1,1,1,1};
        for(int i = 2; i<=n; i++){
            dp[i][0] = dp[i-1][1];
            dp[i][1] = (dp[i-1][0] + dp[i-1][2])%MOD;
            dp[i][2] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][3] + dp[i-1][4])%MOD;
            dp[i][3] = (dp[i-1][2] + dp[i-1][4])%MOD;
            dp[i][4] = dp[i-1][0];
        }
        return accumulate(dp[n].begin(), dp[n].end(), 0ll)%MOD;
    }
};