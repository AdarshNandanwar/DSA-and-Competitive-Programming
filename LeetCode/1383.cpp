// https://leetcode.com/problems/maximum-performance-of-a-team/

// Method 1 (Sorting, Priority Queue, O(nlogn)):

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        long long res = 0, total_speed = 0;
        // {efficiency, speed}
        vector<vector<int>> v;
        for(int i = 0; i<n; i++){
            v.push_back({efficiency[i], speed[i]});
        }
        sort(v.begin(), v.end(), greater<vector<int>>());
        // {top k speed}
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i<n; i++){
            total_speed += v[i][1];
            pq.push(v[i][1]);
            if(pq.size() > k){
                total_speed -= pq.top();
                pq.pop();
            } 
            res = max(res, total_speed*v[i][0]);
        }
        return res%1000000007;
    }
};