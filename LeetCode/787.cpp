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

// Alternate Code:

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> cost(n, vector<int>(n, INT_MAX));
        vector<vector<int>> nbrs(n);
        for(const vector<int>& flight:flights){
            nbrs[flight[0]].push_back(flight[1]);
            cost[flight[0]][flight[1]] = flight[2];
        }

        // Dijkstra's Algorithm
        // minCost[i][j] = minCost till i with k hops.
        vector<vector<long>> minCost(n, vector<long>(k+1, INT_MAX));
        // {cost, hops, dest}
        priority_queue<vector<long>, vector<vector<long>>, greater<vector<long>>> pq;
        pq.push({0, 0, src});
        while(!pq.empty()){
            int cur = pq.top()[2];
            long curCost = pq.top()[0];
            int hops = pq.top()[1];
            pq.pop();
            if(cur == dst){
                return curCost;
            }
            if(hops-1 == k){
                continue;
            }
            if(curCost >= minCost[cur][hops]){
                continue;
            }
            minCost[cur][hops] = curCost;
            for(const int nbr:nbrs[cur]){
                pq.push({curCost + cost[cur][nbr], hops+1, nbr});
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