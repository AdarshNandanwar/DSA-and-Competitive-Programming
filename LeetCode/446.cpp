// https://leetcode.com/problems/arithmetic-slices-ii-subsequence/

// Method 1 (2D DP, O(n*n)):

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        long count = 0;
        // count = number of APs with n > 1
        vector<unordered_map<long, int>> dp(n);
        // dp[i][j] = number of AP ending at i with delta = j and n > 1
        for(int i = 0; i<n; i++){
            for(int j = 0; j<i; j++){
                long delta = (long)nums[i] - nums[j];
                dp[i][delta] += (1 + dp[j][delta]);
                count += dp[j][delta];
            }
        }
        return count;
    }
};

// Alternate Code:

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        long count = 0;
        // count = number of APs with n > 1
        vector<unordered_map<long, int>> dp(n);
        // dp[i][j] = number of AP ending at i with delta = j and n > 1
        for(int i = 0; i<n; i++){
            for(int j = 0; j<i; j++){
                long delta = (long)nums[i] - nums[j];
                dp[i][delta] += (1 + dp[j][delta]);
                count += (1 + dp[j][delta]);
            }
        }
        // return number of APs with n > 2
        return count - (n*(n-1))/2;
    }
};

// Alternate Code:

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

// Method 2 (3D DP, O(n*n*n)):

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        unordered_map<int, unordered_map<long, unordered_map<int, int>>> arithmeticSliceCount;
        // longestArithmeticSlice[i][j][k] = count of arithmetic slice ending at index i with delta j wth length k

        // 1 2 2 3
        // 
        // [1][1][2] = 1
        // [2][1][2] = 1, [2][0][2] = 1
        // [3][2][2] = 1, [3][1][2] = 2, [3][1][3] = 2

        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                long delta = (long)nums[i]-nums[j];
                arithmeticSliceCount[i][delta][2]++;
                if(arithmeticSliceCount[j].count(delta)){
                    for(auto &k:arithmeticSliceCount[j][delta]){
                        arithmeticSliceCount[i][delta][k.first+1] += k.second;
                        count += k.second;  // since (k.first+1) is always >= 3, no need to check
                    }
                }
            }
        }
        return count;
    }
};
