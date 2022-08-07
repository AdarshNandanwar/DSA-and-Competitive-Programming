// https://leetcode.com/problems/network-delay-time/

// Method 1 (Dikstra's Algorithm, O(ElogV)):

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Dijkstra's Algorithm
        
        // {dest, weight}
        vector<vector<pair<int, int>>> nbrs(n);
        for(auto & edge:times){
            int src = edge[0]-1;
            int dest = edge[1]-1;
            int weight = edge[2];
            nbrs[src].push_back(make_pair(dest, weight));
        }
        // {prefixCost, dest}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> shortestDistance(n, INT_MAX);
        shortestDistance[k-1] = 0;
        pq.push(make_pair(0, k-1));
        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();
            int src = cur.second;
            int prefixWeight = cur.first;
            if(prefixWeight > shortestDistance[src]){
                continue;
            }
            for(auto & nbr:nbrs[src]){
                int dest = nbr.first;
                int weight = nbr.second;
                int nbrPathWeight = prefixWeight+weight;
                if(shortestDistance[dest] > nbrPathWeight){
                    shortestDistance[dest] = nbrPathWeight;
                    pq.push(make_pair(nbrPathWeight, dest));
                }
            }
        }
        int minTime = *max_element(shortestDistance.begin(), shortestDistance.end());
        return minTime == INT_MAX ? -1 : minTime;
    }
};