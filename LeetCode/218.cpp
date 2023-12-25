// https://leetcode.com/problems/the-skyline-problem/

// Method 1 (Ordered Map, Priority Queue/Min Heap, O(nlogn)):

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

// Method 1 (Ordered Map, Priority Queue/Min Heap, O(nlogn)):

class Solution {
    void raiseSkyline(vector<vector<int>> & skyline, int x, int y){
        if(!skyline.empty()){
            if(skyline.back()[1] >= y){
                return;
            } else {
                if(skyline.back()[0] == x){
                    skyline.pop_back();
                }
            }             
        }
        skyline.push_back({x, y});
    }
    vector<vector<int>> cleanupSkyline(const vector<vector<int>> & skyline){
        vector<vector<int>> cleanedSkyline;
        int n = skyline.size();
        cleanedSkyline.push_back(skyline[0]);
        for(int i=1; i<n; i++){
            if(skyline[i][1] == skyline[i-1][1]){
                continue;
            }
            cleanedSkyline.push_back(skyline[i]);
        }
        return cleanedSkyline;
    }
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> skyline;
        int n = buildings.size();
        sort(buildings.begin(), buildings.end());
        // {right, height}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // {height: count}
        map<int, int> freq;
        
        for(auto & building:buildings){
            int height = building[2];
            int right = building[1];
            int left = building[0];
            while(!pq.empty() and pq.top().first<=left){
                int prevHeight = pq.top().second;
                int prevRight = pq.top().first;
                pq.pop();
                int maxHeight = freq.rbegin()->first;
                bool wasMaxHeight = (prevHeight == maxHeight);
                freq[prevHeight]--;
                if(freq[prevHeight] == 0){
                    freq.erase(prevHeight);
                }
                if(wasMaxHeight){
                    int nextHeight = 0;
                    if(!freq.empty()){
                        nextHeight = freq.rbegin()->first;
                    }
                    if(skyline.empty()){
                        skyline.push_back({prevRight, nextHeight});
                    } else {
                        if(skyline.back()[0]==prevRight){
                            skyline.pop_back();
                        }
                        skyline.push_back({prevRight, nextHeight});
                    }                    
                }                
            }
            raiseSkyline(skyline, left, height);
            freq[height]++;
            pq.push({right, height});
        }
        
        // clear priority queue buffer
        while(!pq.empty()){
            int prevHeight = pq.top().second;
            int prevRight = pq.top().first;
            pq.pop();
            int maxHeight = freq.rbegin()->first;
            bool wasMaxHeight = (prevHeight == maxHeight);
            freq[prevHeight]--;
            if(freq[prevHeight] == 0){
                freq.erase(prevHeight);
            }
            if(wasMaxHeight){
                int nextHeight = 0;
                if(!freq.empty()){
                    nextHeight = freq.rbegin()->first;
                }
                if(skyline.empty()){
                    skyline.push_back({prevRight, nextHeight});
                } else {
                    if(skyline.back()[0]==prevRight){
                        skyline.pop_back();
                    }
                    skyline.push_back({prevRight, nextHeight});
                }                    
            }                
        }
        
        skyline = cleanupSkyline(skyline);
        
        return skyline;
    }
};