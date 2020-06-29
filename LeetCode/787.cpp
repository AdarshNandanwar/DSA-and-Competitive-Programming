// https://leetcode.com/problems/cheapest-flights-within-k-stops/

// Method 1 (Dijkstra's Algorithm):

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        
        int curCity, curCost, curStops, nbrCity, nbrCost;
        
        vector<vector<pair<int, int>>> adjList(n);
        // {price, dest}
        for(auto f:flights){
            adjList[f[0]].push_back({f[2], f[1]});      
        }
        
        // Dijkstra's Algorithm
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        // < cumCost, < stops, dest > >
        
        pq.push({0, {0, src}});
        
        while(!pq.empty()){
            curCity = pq.top().second.second;
            curCost = pq.top().first;
            curStops = pq.top().second.first;
            pq.pop();
            
            if(curStops-1 > K) continue;
            
            if(dst == curCity){
                return curCost;
            }
            
            for(auto nbr:adjList[curCity]){
                nbrCity = nbr.second;
                nbrCost = nbr.first;
                if(curStops <= K){
                    pq.push({curCost+nbrCost, {curStops+1, nbrCity}});
                }
            }
        }
        
        return -1;       
    }
};

// Method 2 (Bellman Ford Algorithm):

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        int nbrCity, flightCost;
        bool noChange;
        vector<vector<pair<int, int>>> adjList(n);
        // {price, dest}
        for(auto f:flights){
            adjList[f[0]].push_back({f[2], f[1]});      
        }
        
        // Bellman Ford Algorithm
        
        vector<int> cost(n, INT_MAX);
        cost[src] = 0;
        
        for(int i = 0; i<K+1; i++){
            vector<int> temp(cost);     // modification
            noChange = true;
            for(int j = 0; j<n; j++){
                if(cost[j] == INT_MAX) continue;
                for(auto nbr:adjList[j]){
                    nbrCity = nbr.second;
                    flightCost = nbr.first;
                    if(cost[nbrCity] > cost[j]+flightCost){
                        temp[nbrCity] = min(temp[nbrCity], cost[j]+flightCost);
                        noChange = false;
                    }
                }
            }
            cost = temp;                // modification
            if(noChange) break;
        }
        
        return cost[dst] == INT_MAX ? -1 : cost[dst];
    }
};