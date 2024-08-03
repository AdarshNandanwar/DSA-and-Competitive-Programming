// https://leetcode.com/problems/student-attendance-record-ii/

// Method 1 (3D DP, O(n) time, O(n) space):

#define MOD 1000000007

class Solution {
    int helper(const int n, const int index, int absentDays, int consecutiveLateDays, vector<vector<vector<int>>> & dp){
        if(index == n){
            return 1;
        }
        if(dp[index][absentDays][consecutiveLateDays] != -1){
            return dp[index][absentDays][consecutiveLateDays];
        }

        // Present
        int res = helper(n, index+1, absentDays, 0, dp);
        // Absent
        if(absentDays < 1){
            res = (res+helper(n, index+1, absentDays+1, 0, dp))%MOD;
        }
        // Late
        if(consecutiveLateDays < 2){
            res = (res+helper(n, index+1, absentDays, consecutiveLateDays+1, dp))%MOD;
        }

        return dp[index][absentDays][consecutiveLateDays] = res;
    }
public:
    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return helper(n, 0, 0, 0, dp);
    }
};
