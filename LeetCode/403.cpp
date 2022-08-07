// https://leetcode.com/problems/frog-jump/

// Method 1 (2D DP with optimization, O(n*n)):

class Solution {
public:    
    bool canCross(vector<int>& stones) {
        long n = stones.size();
        // dp[i][j] = is it possible to each index i with last jump being of j unit.
        // max valid jump to reach index i will never exceed i units.
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        dp[0][0] = true;
        for(long i=1; i<n; i++){
            for(long j=0; j<i; j++){
                long jump = stones[i]-stones[j];
                if(jump>i) continue;    // optimization
                if(0<=jump and jump<n and dp[j][jump]) dp[i][jump] = true;
                if(0<=(jump-1) and (jump-1)<n and dp[j][jump-1]) dp[i][jump] = true;
                if(0<=(jump+1) and (jump+1)<n and dp[j][jump+1]) dp[i][jump] = true;
            }
        }
        return *max_element(dp[n-1].begin(), dp[n-1].end());
    }
};

// Method 2 (Hash Map 2D DP with optimization, TLE, O(n*n):

class Solution {
public:    
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        // dp[i][j] = is it possible to each index i with last jump being of j unit.
        // max valid jump to reach index i will never exceed i units.
        vector<unordered_map<long, bool>> dp(n, unordered_map<long, bool>());
        dp[0][0] = true;
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                long jump = stones[i]-stones[j];
                if(jump>i) continue;    // optimization
                if(0<=jump and jump<n and dp[j][jump]) dp[i][jump] = true;
                if(0<=(jump-1) and (jump-1)<n and dp[j][jump-1]) dp[i][jump] = true;
                if(0<=(jump+1) and (jump+1)<n and dp[j][jump+1]) dp[i][jump] = true;
            }
        }
        for(auto &i:dp[n-1]){
            if(i.second) return true;
        }
        return false;
    }
};

// Method 3 (Hash Map 2D DP, TLE, O(n*(n*n)):

class Solution {
public:    
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        // dp[i][j] = is it possible to each index i with last jump being of j unit.
        vector<unordered_map<long, bool>> dp(n, unordered_map<long, bool>());
        dp[0][0] = true;
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                long jump = stones[i]-stones[j];
                if(0<=jump and jump<n and dp[j][jump]) dp[i][jump] = true;
                if(0<=(jump-1) and (jump-1)<n and dp[j][jump-1]) dp[i][jump] = true;
                if(0<=(jump+1) and (jump+1)<n and dp[j][jump+1]) dp[i][jump] = true;
            }
        }
        for(auto &i:dp[n-1]){
            if(i.second) return true;
        }
        return false;
    }
};

// Method 4 (2D DP with Binary Search, TLE, O(n*n*logn)):

class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        // dp[i][j] = is it possible to each index i with last jump being of j unit.
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        dp[0][0] = true;
        for(int i=1; i<n; i++){
            for(int j=1; j<=i; j++){
                if(binary_search(stones.begin(), stones.begin()+i, stones[i]-j)){
                    int index = lower_bound(stones.begin(), stones.begin()+i, stones[i]-j)-stones.begin();
                    dp[i][j] = dp[i][j] or dp[index][j];
                    if(j-1>=0){
                        dp[i][j] = dp[i][j] or dp[index][j-1];
                    }
                    if(j+1<n){
                        dp[i][j] = dp[i][j] or dp[index][j+1];
                    }
                }
            }
        }
        return *max_element(dp[n-1].begin(), dp[n-1].end());
    }
};