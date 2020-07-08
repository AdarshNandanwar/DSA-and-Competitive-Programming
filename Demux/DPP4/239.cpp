// https://leetcode.com/problems/sliding-window-maximum/

// Method 1 (Deque, O(n)):

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        // dq of indexes
        deque<int> dq;
        for(int i = 0; i<n; i++){
            if(!dq.empty() and dq.front() == i-k) dq.pop_front();
            while(!dq.empty() and nums[dq.back()] < nums[i]) dq.pop_back();
            dq.push_back(i);
            if(i>=k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};

// Method 2 (Map, O(nlogk)):

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        map<int, int> m;
        for(int i = 0; i<k; i++) m[nums[i]]++;
        ans.push_back(prev(m.end())->first);
        for(int i = k; i<n; i++){
            m[nums[i]]++;
            if(m[nums[i-k]] == 1) m.erase(nums[i-k]);
            else m[nums[i-k]]--;
            ans.push_back(prev(m.end())->first);
        }
        return ans;
    }
};

// Method 3 (Max Heap, O(nlog(n))):

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> m;
        priority_queue<int, vector<int>> pq;
        for(int i = 0; i<k; i++){
            pq.push(nums[i]);
            m[nums[i]]++;
        }
        ans.push_back(pq.top());
        for(int i = k; i<n; i++){
            m[nums[i]]++;
            m[nums[i-k]]--;
            pq.push(nums[i]);
            int t = pq.top();
            while(m[t] == 0){
                pq.pop();
                t = pq.top();
            }
            ans.push_back(t);
        }
        return ans;
    }
};