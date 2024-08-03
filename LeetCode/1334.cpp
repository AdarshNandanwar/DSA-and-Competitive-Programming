// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

// Method 1 (Dijkstra's Algorithm, O(V*ElogV)):

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // {nbr, weight}
        vector<vector<pair<int, int>>> nbrs(n);
        for(auto & edge:edges){
            nbrs[edge[0]].push_back(make_pair(edge[1], edge[2]));
            nbrs[edge[1]].push_back(make_pair(edge[0], edge[2]));
        }

        int minReachable = INT_MAX;
        int minReachableCity = 0;
        for(int i=0; i<n; i++){
            int reachable = 0;

            // {curCost, cur}
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            vector<bool> visited(n, false);
            pq.push(make_pair(0, i));
            while(!pq.empty()){
                int curWeight = pq.top().first;
                int cur = pq.top().second;
                pq.pop();
                if(visited[cur]){
                    continue;
                }
                visited[cur] = true;
                for(auto & nbr:nbrs[cur]){
                    if(!visited[nbr.first] and curWeight + nbr.second <= distanceThreshold){
                        pq.push(make_pair(curWeight + nbr.second, nbr.first));
                    }
                }
                reachable++;
            }
            
            if(reachable <= minReachable){
                minReachable = reachable;
                minReachableCity = i;
            }
        }

        return minReachableCity;
    }
};
