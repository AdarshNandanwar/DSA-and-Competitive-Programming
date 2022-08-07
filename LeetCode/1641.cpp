// https://leetcode.com/problems/count-sorted-vowel-strings/

// Method 2 (Maths, O(1)):

// Sorted strings will always have continuous letters.
// So, find ways to insert k-1 partitions between n letters.
// Only one type of letter is present between any 2 partition.
// This is equal to number of ways to select 4 positions from n+k-1 places.
// Ans = (n+k-1)C(k-1)

class Solution {
public:
    int countVowelStrings(int n) {
        return (n+4)*(n+3)*(n+2)*(n+1)/24;
    }
};

// Method 1 (2D DP, O(n)):

class Solution {
public:
    int countVowelStrings(int n) {
        // dp[i][j] = number of ways to make n length sorted string using j unique letters.
        // dp[i][j] = dp[i-1][1] + dp[i-1][2] + ... + dp[i-1][j]
        vector<vector<int>> dp(n+1, vector<int>(6, 1));
        for(int i=1; i<=n; i++){
            int prefixSum = 0;
            for(int j=1; j<=5; j++){
                prefixSum += dp[i-1][j];
                dp[i][j] = prefixSum;
            }
        }
        return dp[n][5];
    }
};