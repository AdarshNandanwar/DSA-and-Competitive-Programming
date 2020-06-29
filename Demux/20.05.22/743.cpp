// https://leetcode.com/problems/network-delay-time/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        K--;
        int curNode, curTime, nbrNode, nbrTime, maxDelay = INT_MIN;
        vector<vector<pair<int, int>>> g(N);     // u, v, w
        for(auto i:times){
            g[i[0]-1].push_back({i[1]-1, i[2]});
        }
        
        vector<int> delay(N, INT_MAX);
        
        // Dijkstra's Algorithm
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;      // {cumulative time, v}
        
        delay[K] = 0;
        pq.push({delay[K], K});
        
        while(!pq.empty()){
            curNode = pq.top().second;
            curTime = pq.top().first;
            pq.pop();
            
            if(delay[curNode] < curTime) continue;
                
            for(auto nbr:g[curNode]){
                nbrNode = nbr.first;
                nbrTime = nbr.second;
                if(delay[nbrNode] > curTime+nbrTime){
                    delay[nbrNode] = curTime+nbrTime;
                    pq.push({delay[nbrNode], nbrNode});
                }
            }
        }
        
        for(auto i:delay){
            if(i == INT_MAX) return -1;
            maxDelay = max(maxDelay, i);
        }
        
        return maxDelay;
    }
};