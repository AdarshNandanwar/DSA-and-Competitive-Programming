# https://leetcode.com/problems/arithmetic-slices-ii-subsequence/

# Method 1 (2D DP, O(n2)):

class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        n = len(nums)
        res = 0
        # dp[i][j] = number of AP ending at i with d = j and n > 1
        dp = [{} for i in range(n)]
        for i in range(n):
            for j in range(i):
                d = nums[i]-nums[j]
                dp_i = dp[i].get(d) if dp[i].get(d) else 0
                dp_j = dp[j].get(d) if dp[j].get(d) else 0
                dp[i][d] = 1+dp_i+dp_j
        # res = number of APs with n > 1
        for i in dp:
            for _, j in i.items():
                res += j
        # return = number of APs with n > 2
        return int(res - (n*(n-1))/2)