#include<bits/stdc++.h>
using namespace std;

int dijkstra(int n, vector<vector<int>>& edges, vector<int>& weights, int start_node, int end_node) {
    // {weight, nbr}
    vector<vector<pair<int, int>>> nbrs(n);
    int e = edges.size();
    for(int i=0; i<e; i++){
        nbrs[edges[i][0]].push_back(make_pair(weights[i], edges[i][1]));
        nbrs[edges[i][1]].push_back(make_pair(weights[i], edges[i][0]));
    }

    // {weight, nbr}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> visited(n);
    pq.push(make_pair(1, start_node));
    while(!pq.empty()){
        auto top = pq.top();
        int cur = top.second;
        int pathWeight = top.first;
        pq.pop();
        if(cur == end_node){
            return pathWeight;
        }
        if(visited[cur]){
            continue;
        }
        visited[cur] = true;
        for(auto nbr:nbrs[cur]){
            pq.push(make_pair(pathWeight + nbr.first, nbr.second));
        }
    }

    return 0;
}

int main(){
    return 0;
}