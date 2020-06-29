// https://leetcode.com/problems/frog-jump/

// Method 1 (DP, Top down):

class Solution {
public:
    
    bool helper(vector<int> & stones, int index, int hop, vector<vector<int>> & dp){
        if(index == stones.size()-1) return true;
        
        if(dp[index][hop] != -1){
            return dp[index][hop];
        }
        
        bool res = false;
        
        for(int k = hop-1; k<=hop+1; k++){
            if(k <= 0) continue;
            if(binary_search(stones.begin(), stones.end(), stones[index]+k)){
                res = helper(stones, lower_bound(stones.begin(), stones.end(), stones[index]+k)-stones.begin(), k, dp);
            }
            if(res) break;
        }
        
        dp[index][hop] = res;
        return res;
    }
    
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int>> dp(n, vector<int>(1105, -1));
        return helper(stones, 0, 0, dp);
    }
};  