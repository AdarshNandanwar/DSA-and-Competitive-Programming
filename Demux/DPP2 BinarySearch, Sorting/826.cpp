// https://leetcode.com/problems/most-profit-assigning-work/

class Solution {
public:
    
    int search(vector<pair<int, int>> & v, int d){
        int lo = 0, hi = v.size()-1, mid;
        
        // FT last F
        // d<v[mid].first
        
        while(lo<hi){
            mid = lo+(hi-lo+1)/2;
            if(d<v[mid].first){
                hi = mid-1;
            } else {
                lo = mid;
            }
        }
        if(d<v[lo].first){
            return 0;
        } else {
            return v[lo].second;
        }
    }
    
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size(), maxProfitTillNow = 0, ans = 0;
        if(n == 0 || worker.size() == 0) return 0;
        vector<pair<int, int>> v;
        for(int i = 0; i<n; i++) v.push_back({difficulty[i], profit[i]});
        sort(v.begin(), v.end(), [](const pair<int, int> & a, const pair<int, int> & b){
            return a.first==b.first?a.second>b.second:a.first<b.first;
        });
        for(int i = 0; i<n; i++) v[i].second = maxProfitTillNow = max(maxProfitTillNow, v[i].second);
        for(auto w:worker) ans += search(v, w);
        return ans;
    }
};