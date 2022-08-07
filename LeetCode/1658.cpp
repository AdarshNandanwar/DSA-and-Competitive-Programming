// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/

// Method 1 (Sliding Window, O(n)):

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // sliding window
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(x>sum){
            return -1;
        }
        int targetSum = sum-x, curSum = 0, longestLength = INT_MIN;
        // [left, right)
        int left = 0, right = 0, n = nums.size();
        while(right<n){
            while(right<n and curSum < targetSum){
                curSum += nums[right];
                right++;
            }
            while(left<right and curSum > targetSum){
                curSum -= nums[left];
                left++;                
            }
            if(curSum == targetSum){
                longestLength = max(longestLength, right-left);
                curSum += nums[right];
                right++;
            }
        }
        return longestLength == INT_MIN ? -1 : n-longestLength;
    }
};

// Method 2 (Prefix Suffix, Hash Table, O(n)):

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // [3,2,20,1,1,3]
        // prefixSum [3,5,25,26,27,30]
        // suffixSum [30,27,25,5,4,3]
        
        int n = nums.size(), minOperations = INT_MAX;
        int prefixSum = 0, suffixSum = 0;
        
        // {prefixSum, minimum length of prfix that has the sum = prefixSum}
        unordered_map<int, int> prefixCount, suffixCount;
        for(int i=0; i<n; i++){
            prefixSum += nums[i];
            if(!prefixCount.count(prefixSum)){
                prefixCount[prefixSum] = i+1;
            }
        }
        for(int i=n-1; i>=0; i--){
            suffixSum += nums[i];
            if(!suffixCount.count(suffixSum)){
                suffixCount[suffixSum] = n-i;
            }
        }
        int sum = suffixSum;
        prefixCount[0] = 0;
        suffixCount[0] = 0;
        prefixCount[sum] = n;
        suffixCount[sum] = n;
        
        for(auto &i:prefixCount){
            int target = x-i.first;
            if(suffixCount.count(target)){
                // ensuring prefix and suffix never overlap
                int totalCount = i.second+suffixCount[target];
                if(totalCount <= n){
                    minOperations = min(minOperations, totalCount);
                }
            }
        }
        
        return minOperations == INT_MAX ? -1 : minOperations;
    }
};

// Method 3 (Prefix Suffix, Binary Search, O(nlogn)):

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // [3,2,20,1,1,3]
        // prefixSum [3,5,25,26,27,30]
        // suffixSum [30,27,25,5,4,3]
        // Binary Search
        
        int n = nums.size(), minOperations = INT_MAX;
        vector<int> prefixSum(nums), suffixSum(nums);
        for(int i=1; i<n; i++){
            prefixSum[i] += prefixSum[i-1];
        }
        for(int i=n-2; i>=0; i--){
            suffixSum[i] += suffixSum[i+1];
        }
        
        // prefix only
        if(binary_search(prefixSum.begin(), prefixSum.end(), x)){
            int index = lower_bound(prefixSum.begin(), prefixSum.end(), x)-prefixSum.begin();
            minOperations = min(minOperations, index+1);
        }
        
        // suffix only
        if(binary_search(suffixSum.begin(), suffixSum.end(), x, greater<int>())){
            int index = lower_bound(suffixSum.begin(), suffixSum.end(), x, greater<int>())-suffixSum.begin();
            minOperations = min(minOperations, n-index);
        }
        
        
        // both prefix and suffix
        for(int i=n-1; i>0; i--){
            int target = x-suffixSum[i];
            if(target <= 0){
                break;
            }
            if(binary_search(prefixSum.begin(), prefixSum.begin()+i-1, target)){
                int index = lower_bound(prefixSum.begin(), prefixSum.begin()+i-1, target)-prefixSum.begin();
                minOperations = min(minOperations, n-i+index+1);
            }
        }
        return minOperations == INT_MAX ? -1 : minOperations;
    }
};