// https://leetcode.com/problems/the-skyline-problem/

// Method 1 (Min Heap, Ordered Map, O(nlogn)):

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int n = buildings.size();
        vector<vector<int>> ans;
        // {height, count}
        map<int, int> height;
        height[0]++;
        // {right, height}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i=0; i<n; i++){
            while(!pq.empty() and buildings[i][0] >= pq.top().first){
                auto cur = pq.top();
                pq.pop();
                height[cur.second]--;
                if(height[cur.second] == 0){
                    height.erase(cur.second);
                    if(prev(height.end())->first < cur.second){
                        ans.push_back({cur.first, prev(height.end())->first});
                    }
                }
            }
            if(ans.size() and ans[ans.size()-1][0]==buildings[i][0]){
                // new building starts at the last skyline data point
                ans.pop_back();
                int max_height = max(prev(height.end())->first, buildings[i][2]);
                if(!ans.size() or ans[ans.size()-1][1]!=max_height){
                    // new point not in a horizontal line with second last skyline data point
                    ans.push_back({buildings[i][0], max_height});
                }
            } else {
                // only add building in the skyline if its the highest in ordered map
                if(prev(height.end())->first < buildings[i][2]){
                    ans.push_back({buildings[i][0], buildings[i][2]});
                }                
            }          
            pq.push(make_pair(buildings[i][1], buildings[i][2]));
            height[buildings[i][2]]++;
        }
        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();
            height[cur.second]--;
            if(height[cur.second] == 0){
                height.erase(cur.second);
                if(prev(height.end())->first < cur.second){
                    ans.push_back({cur.first, prev(height.end())->first});
                }
            }
        }
        return ans;
    }
};