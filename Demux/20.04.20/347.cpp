// https://leetcode.com/problems/top-k-frequent-elements/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;;
        // min heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;   
        
        for(int i = 0; i<n; i++){
            freq[nums[i]]++;
        }
        
        // O(klogk)
        auto itr = freq.begin();
        for(int count = 0; count<k and itr!=freq.end(); count++, itr++)
            q.push(make_pair(itr->second, itr->first));
        
        // O(nlogk)
        while(itr != freq.end()){
            if(q.top().first < itr->second){
                q.pop();
                q.push(make_pair(itr->second, itr->first));
            }
            itr++;
        }
        
        vector<int> ans;
        
        while(!q.empty()){
            ans.push_back(q.top().second);
            q.pop();
        }
        
        return ans;
    }
};