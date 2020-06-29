// Prim's Algorithm

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> primMST(int n, vector<vector<int>> & edges){
    int curS, curD, curW, nbrN, nbrW;

    // {weight, v}
    vector<vector<pair<int, int>>> adjList(n);

    for(auto e:edges){
        adjList[e[0]].push_back({e[2], e[1]});
        adjList[e[1]].push_back({e[2], e[0]});
    }

    // {{src, des, w}}
    vector<vector<int>> mst;    
    vector<bool> visited(n, false);
    // {weight, {src, des}}
    priority_queue<pair<int, pair<int, int>>, vector <pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
  
    int src = 0;
    pq.push({0, {src, src}});
    
    while (!pq.empty()) 
    {
        if(mst.size() == n-1) break;
        curS = pq.top().second.first; 
        curD = pq.top().second.second; 
        curW = pq.top().first; 
        pq.pop();
        if(visited[curD]) continue;
        visited[curD] = true;
        if(curD != src) mst.push_back({curS, curD, curW});
        for(auto nbr:adjList[curD]){
            nbrN = nbr.second;
            nbrW = nbr.first;
            pq.push({nbrW, {curD, nbrN}});
        }
    }

    return mst;
}