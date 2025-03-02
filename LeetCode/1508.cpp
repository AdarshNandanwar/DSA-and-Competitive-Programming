// https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/

// Method 1 (Min Heap, O((n + right) * logn)) time, O(n) space):

#define MOD 1000000007

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        // {sum, end index (inclusive)}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for(int i=0; i<n; i++){
            pq.push({nums[i], i});
        }

        int ans = 0;
        for(int i=0; i<right; i++){
            auto cur = pq.top();
            pq.pop();

            int nextIndex = cur[1] + 1;
            if(nextIndex < n){
                int nextSum = (cur[0] + nums[nextIndex]) % MOD;
                pq.push({nextSum, nextIndex});
            }

            if(i >= left-1){
                ans = (ans + cur[0]) % MOD;
            }
        }

        return ans;
    }
};

// Method 2 (Brute Force, O(n2logn) time, O(n) space):

#define MOD 1000000007

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> suffixSum(n+1);
        for(int i=n-1; i>=0; i--){
            suffixSum[i] = (suffixSum[i+1] + nums[i]) % MOD;
        }
        vector<int> subsetSums;
        // [i, j)
        for(int i=0; i<n; i++){
            for(int j=i+1; j<=n; j++){
                subsetSums.push_back((suffixSum[i] - suffixSum[j]) % MOD);
            }
        }
        sort(subsetSums.begin(), subsetSums.end());

        int ans = 0;
        for(int i=left-1; i<=right-1; i++){
            ans = (ans + subsetSums[i]) % MOD;
        }

        return ans < 0 ? MOD + ans : ans;
    }
};
