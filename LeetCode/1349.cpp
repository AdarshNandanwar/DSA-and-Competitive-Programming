// https://leetcode.com/problems/maximum-students-taking-exam/

// Method 1 (DP Bit Masking):

class Solution {
public:
    
    bool isValid(const vector<char> & seats, const int prevMask, const int mask, const int & m){
        for(int i = 0; i<m; i++){
            if(mask&(1<<i)){
                if(seats[i] == '#') return 0;
                if(i-1>=0 and (prevMask&(1<<(i-1)))) return 0;
                if(i+1<m and (prevMask&(1<<(i+1)))) return 0;
                if(i-1>=0 and (mask&(1<<(i-1)))) return 0;
            }
        }
        return 1;
    }
    
    int helper(const vector<vector<char>> & seats, int prevMask, int index, vector<vector<int>> & dp){
        int n = seats.size(), m = seats[0].size(), res = 0;
        if(index == n) return 0;
        if(dp[prevMask][index] != -1) return dp[prevMask][index];
        for(int mask = 0; mask<(1<<m); mask++){
            if(isValid(seats[index], prevMask, mask, m)){
                res = max(res, __builtin_popcount(mask)+helper(seats, mask, index+1, dp));
            }
        }
        return dp[prevMask][index] = res;
    }
    
    int maxStudents(vector<vector<char>>& seats) {
        int n = seats.size(), m = seats[0].size();
        vector<vector<int>> dp(1<<m, vector<int>(n, -1));
        return helper(seats, 0, 0, dp);
    }
};