// https://leetcode.com/problems/jump-game-vi/

// Method 1 (Deque, Sliding Window Maximum, O(n)):

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<int> dq;
        dq.push_back(0);
        for(int i = 1; i<nums.size(); i++){
            while(!dq.empty() and i-dq.front() > k) dq.pop_front();
            nums[i] += nums[dq.front()];
            while(!dq.empty() and nums[dq.back()] <= nums[i]) dq.pop_back();
            dq.push_back(i);
        }
        return nums[nums.size()-1];
    }
};

// Method 2 (Max Heap, O(nlogn)):

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int res = nums[0];
        // {score, index}
        priority_queue<vector<int>, vector<vector<int>>> pq;
        pq.push({nums[0], 0});
        for(int i = 1; i<nums.size(); i++){
            while(!pq.empty() and i-pq.top()[1]>k) pq.pop();
            auto cur = pq.top();
            pq.push({cur[0]+nums[i], i});
            res = cur[0]+nums[i];
        }
        return res;
    }
};