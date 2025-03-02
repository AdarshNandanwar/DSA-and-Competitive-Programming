// https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii/

// Method 1 (Max Heap, O(n)):

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long, vector<long>, greater<long>> pq;
        for(auto num:nums){
            pq.push(num);
        }
        int operationCount = 0;
        while(pq.size()>=2 and pq.top()<k){
            long x = pq.top();
            pq.pop();
            long y = pq.top();
            pq.pop();
            pq.push(min(x, y) * 2 + max(x, y));
            operationCount++;
        }
        return operationCount;
    }
};