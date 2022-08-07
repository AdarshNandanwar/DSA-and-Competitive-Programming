// https://leetcode.com/problems/jump-game-vi/

// Method 1 (Deque, Sliding Window Maximum, O(n) time, O(1) space):

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

// Method 2 (Deque, Sliding Window Macimum, O(n) time, O(k) space):

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size(), curMax;
        // Sliding window maximum
        // {max subsequence sum ending at index, index}
        deque<pair<int, int>> dq;
        dq.push_back(make_pair(nums[0], 0));
        for(int i = 1; i<n; i++){
            while(!dq.empty() and dq.front().second < i-k){
                dq.pop_front();
            }
            curMax = dq.front().first+nums[i];
            while(!dq.empty() and dq.back().first <= curMax){
                dq.pop_back();
            }
            dq.push_back(make_pair(curMax, i));
        }
        return dq.back().first;
    }
};

// Method 3 (Max Heap, O(nlogn)):

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size(), lastCost = nums[0];
        // {Max subsequence sum ending at index, Index}
        priority_queue<pair<int, int>> pq;
        pq.push(make_pair(nums[0], 0));
        for(int i=1; i<n; i++){
            int prevMax = INT_MIN;
            while(!pq.empty()){
                auto cur = pq.top();
                prevMax = cur.first;
                if(cur.second >= i-k){
                    break;
                } else {
                    pq.pop();
                }
            }
            lastCost = prevMax+nums[i];
            pq.push(make_pair(lastCost, i));
        }
        return lastCost;
    }
};

// Alternate Code:

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