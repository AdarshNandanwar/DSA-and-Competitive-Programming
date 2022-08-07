// https://leetcode.com/problems/ones-and-zeroes/

// Method 1 (DP, Bottom Up)

class Solution {
public:
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        // strings frequency
        vector<vector<int>> freq(strs.size(), vector<int>(2, 0));
        for(int i = 0; i<strs.size(); i++){
            for(auto & j:strs[i]) freq[i][j-'0']++;            
        }

        // DP
        vector<vector<vector<int>>> dp(strs.size()+1, vector<vector<int>>(m+1, vector<int>(n+1, 0)));
        for(int i = strs.size()-1; i>=0; i--){
            for(int j = 0; j<=m; j++){
                for(int k = 0; k<=n; k++){
                    dp[i][j][k] = dp[i+1][j][k];
                    if(j-freq[i][0]>=0 and k-freq[i][1]>=0){
                        dp[i][j][k] = max(dp[i][j][k], 1+dp[i+1][j-freq[i][0]][k-freq[i][1]]);
                    }
                }
            }
        }
        
        return dp[0][m][n];
    }
};

// Method 2 (DP, Top Down)

class Solution {
public:
    
    int helper(vector<string>& strs, int index, int m, int n, vector<vector<vector<int>>> & dp){
        if(index == strs.size()) return 0;
        if(dp[index][m][n] != -1) return dp[index][m][n];
        int res = 0, ones = 0, zeros = 0;
        for(auto c:strs[index]){
            if(c == '0') zeros++;
            else ones++;
        }
        if(zeros<=m and ones<=n) res = max(res, 1+helper(strs, index+1, m-zeros, n-ones, dp));
        res = max(res, helper(strs, index+1, m, n, dp));
        return dp[index][m][n] = res;
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        // dp[i][j][k] = number of strings in [i..n) that can be formed using j 0s and k 1s
        vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        return helper(strs, 0, m, n, dp);
    }
};

// Alternate Code:

class Solution {
    struct Count{
        int ones;
        int zeros;
        Count(){
            ones = 0;
            zeros = 0;
        }
    };
    int getMaxSubsetSize(const vector<Count> & v, int l, int m, int n, vector<vector<vector<int>>> & dp){
        if(m<0 or n<0){
            return INT_MIN;
        }
        if(l<0){
            return 0;
        }
        if(dp[l][m][n] != -1){
            return dp[l][m][n];
        }
        dp[l][m][n] = max(1+getMaxSubsetSize(v, l-1, m-v[l].zeros, n-v[l].ones, dp),
                          getMaxSubsetSize(v, l-1, m, n, dp));
        return dp[l][m][n];
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<Count> v;
        int l = strs.size();
        for(auto & str:strs){
            Count counter;
            for(auto c:str){
                if(c == '0'){
                    counter.zeros++;
                } else {
                    counter.ones++;
                }
            }
            v.push_back(counter);
        }
        
        // dp[i][j][k] = max subset of v[0..i] using max j zeros and k ones
        vector<vector<vector<int>>> dp(l, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        return getMaxSubsetSize(v, l-1, m, n, dp);
    }
};