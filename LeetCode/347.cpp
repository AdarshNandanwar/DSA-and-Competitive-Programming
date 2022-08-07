// https://leetcode.com/problems/top-k-frequent-elements/

// Method 1(Min Heap, O(nlogk)):

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(auto & num:nums){
            freq[num]++;
        }
        // [freq, val]
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for(auto &i:freq){
            pq.push({i.second, i.first});
            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<int> res;
        while(!pq.empty()){
            auto num = pq.top()[1];
            pq.pop();
            res.push_back(num);
        }
        return res;
    }
};