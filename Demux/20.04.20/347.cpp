// https://leetcode.com/problems/top-k-frequent-elements/

// Method 1 (Priority Queue, O(nlogk)):

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

// Method 2 (LFU Cache Method, O(n)):

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        unordered_map<int, list<int>::iterator> pos;
        vector<list<int>> revFreq(1);
        for(auto i:nums){
            if(freq.count(i)) revFreq[freq[i]].erase(pos[i]);
            freq[i]++;
            if(revFreq.size() <= freq[i]) revFreq.push_back({});
            revFreq[freq[i]].push_back(i);
            pos[i] = prev(revFreq[freq[i]].end());
        }
        vector<int> ans;
        for(int i = revFreq.size()-1; i>=0; i--){
            for(auto j:revFreq[i]){
                ans.push_back(j);
                k--;
                if(k == 0) return ans;
            }
        }
        return ans;
    }
};