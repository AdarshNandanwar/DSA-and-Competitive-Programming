// https://leetcode.com/problems/3sum-closest/

// Method 1 (2 Pointer, O(n2)):

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), minDelta = INT_MAX, closestSum = INT_MAX;
        for(int i=2; i<n; i++){
            int p1 = 0, p2 = i-1;
            while(p1<p2){
                int curSum = nums[p1]+nums[p2]+nums[i];
                int delta = abs(target-curSum);
                if(delta < minDelta){
                    minDelta = delta;
                    closestSum = curSum;
                }
                if(curSum < target){
                    p1++;
                } else if(curSum > target){
                    p2--;
                } else {
                    return target;
                }
            }
        }
        return closestSum;
    }
};

// Method 2 (2 Pointer, Binary Search, O(n2logn)):

class Solution {
    void updateClosestSum(vector<int>& nums, const int & target, const int & i, const int & j, const int & k, int & minDelta, int & closestSum){
        if(i<k and k<j){
            int curSum = nums[i]+nums[j]+nums[k];
            int delta = abs(target-curSum);
            if(delta < minDelta){
                minDelta = delta;
                closestSum = curSum;
            }
        }
    }
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), minDelta = INT_MAX, closestSum = INT_MAX;
        for(int i=0; i<n; i++){
            for(int j=i+2; j<n; j++){
                int toFind = target-nums[i]-nums[j];
                if(toFind <= nums[i]){
                    updateClosestSum(nums, target, i, j, i+1, minDelta, closestSum);
                } else if(toFind >= nums[j]){
                    updateClosestSum(nums, target, i, j, j-1, minDelta, closestSum);
                } else {
                    int k = upper_bound(nums.begin()+i+1, nums.begin()+j, toFind) - nums.begin();
                    updateClosestSum(nums, target, i, j, k, minDelta, closestSum);
                    updateClosestSum(nums, target, i, j, k-1, minDelta, closestSum);
                }
            }
        }
        return closestSum;
    }
};