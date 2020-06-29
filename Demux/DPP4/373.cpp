// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/

// Method 1 (Min Heap, O(klog(n))   k<=n2):

struct Cmp{
    bool operator()(const pair<int, pair<int, int>> & a, const pair<int, pair<int, int>> & b){
        return a.first+a.second.first > b.first+b.second.first;
    }
};


class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size(), n2 = nums2.size(), index;
        vector<vector<int>> ans;
        if(!n1 or !n2) return ans;
        // {val1, {val2, ind2}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, Cmp> pq;
        
        // adding all pairs of {nums1[i], nums2[0]}
        for(auto i:nums1) pq.push({i, {nums2[0], 0}});
        
        while(k-- and !pq.empty()){
            auto t = pq.top();
            pq.pop();
            ans.push_back({t.first, t.second.first});
            index = t.second.second+1;
            if(index<n2) pq.push({t.first, {nums2[index], index}});
        }
        return ans;
    }
};

// Method 2 (Min Heap, O(min(k,n1)*min(k,n2)*log(k))    k<=n2):

struct Cmp{
    bool operator()(const pair<int, int> & a, const pair<int, int> & b){
        return a.first+a.second==b.first+b.second?a.first<b.first:a.first+a.second < b.first+b.second;
    }
};


class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size(), n2 = nums2.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> pq;
        for(int i = 0; i<min(k, n1); i++){
            for(int j = 0; j<min(k, n2); j++){
                pq.push({nums1[i], nums2[j]});
                if(pq.size()>k) pq.pop();
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            auto [i,j] = pq.top();
            pq.pop();
            ans.push_back({i,j});
        }
        return ans;
    }
};