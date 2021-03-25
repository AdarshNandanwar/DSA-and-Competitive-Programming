// https://leetcode.com/problems/stone-game-iii/

// Method 1 (MiniMax Problem):

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n+3, 0);

        // dp[i] =  Difference between the scores of P1 and P2 for sequence
        //          stoneValue [i,n-1] assiming P1 goes first
        //          
        // k = 1, 2, 3
        // { (A-B) in [i:n] } = { totalSum at [i:i+k] } - { (B-A) in [i+k:n] }

        for(int i = n-1; i>=0; i--){
            dp[i] = stoneValue[i]-dp[i+1];
            if(i+1<n) dp[i] = max(dp[i], stoneValue[i]+stoneValue[i+1]-dp[i+2]);
            if(i+2<n) dp[i] = max(dp[i], stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]-dp[i+3]);
        }
        
        if(dp[0]>0) return "Alice";
        else if(dp[0]<0) return "Bob";
        else return "Tie";
    }
};

// Method 2:

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        
        vector<int> cumSum(n+3, 0);
        vector<int> dp(n+3, 0);

        // dp[i] =  Optimal sum if player picks at i in [i:n]
        //          
        // k = 1, 2, 3
        // { A in [i:n] } = { totalSum in [i:i+k] } - { { totalSum in [i+k:n] } - { B in [i+k:n] } }
        //                = { { totalSum in [i:n] } - { B in [i+k:n] } }
        
        for(int i =n-1; i>=0; i--){
            cumSum[i] = stoneValue[i]+cumSum[i+1];
        }
        
        for(int i = n-1; i>=0; i--){
            dp[i] = cumSum[i]-dp[i+1];
            dp[i] = max(dp[i], cumSum[i]-dp[i+2]);
            dp[i] = max(dp[i], cumSum[i]-dp[i+3]);
        }
        
        if(2*dp[0]>cumSum[0]) return "Alice";
        else if(2*dp[0]<cumSum[0]) return "Bob";
        else return "Tie";
    }
};