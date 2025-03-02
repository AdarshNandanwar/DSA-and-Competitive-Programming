// https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i/

// Method 1 (Min Heap, O(n+klogn)):

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for(int i=0; i<n; i++){
            pq.push({nums[i], i});
        }
        while(k--){
            auto cur = pq.top();
            pq.pop();
            int index = cur[1];
            nums[index] *= multiplier;
            pq.push({nums[index], index});
        }
        return nums;
    }
};
