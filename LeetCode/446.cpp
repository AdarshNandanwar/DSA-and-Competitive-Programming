// https://leetcode.com/problems/arithmetic-slices-ii-subsequence/

// Method 1 (2D DP, TLE 101/101, O(n*n)):
// C++ gives TLE for the same algorithm for some reason

typedef long long ll;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        ll n = nums.size(), res = 0;
        // dp[i][j] = number of AP ending at i with d = j and n > 1
        vector<unordered_map<ll, ll>> dp(n);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<i; j++){
                ll d = (ll)nums[i]-(ll)nums[j];
                dp[i][d] += (1+dp[j][d]);
            }
        }
        // res = number of APs with n > 1
        for(int i = 0; i<n; i++){
            for(auto &j:dp[i]){
                res += j.second;
            }
        }
        // return = number of APs with n > 2
        return res-(n*(n-1))/2;
    }
};