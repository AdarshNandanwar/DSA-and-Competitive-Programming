// Dijkstra's Algorithm
// Send Feedback
// Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
// Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices (including source vertex also) using Dijkstra's Algorithm.
// Print the ith vertex number and the distance from source in one line separated by space. Print different vertices in different lines.
// Note : Order of vertices in output doesn't matter.
// Input Format :
// Line 1: Two Integers V and E (separated by space)
// Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
// Output Format :
// In different lines, ith vertex number and its distance from source (separated by space)
// Constraints :
// 2 <= V, E <= 10^5
// Sample Input 1 :
// 4 4
// 0 1 3
// 0 3 5
// 1 2 1
// 2 3 8
// Sample Output 1 :
// 0 0
// 1 3
// 2 4
// 3 5

#include <bits/stdc++.h>
using namespace std;

void solve(int ** edge, int start, int V, bool * visited, int * distance){
    int n = V-1;
    visited[start] = true;
    while(n--){
        int min_dist = INT_MAX, min_index = -1;
        for (int i = 0; i < V; i++)
        {
            if(!visited[i]){
                if(edge[start][i]){
                    distance[i] = min(distance[i], edge[start][i] + distance[start]);
                }
                if(min_dist > distance[i]){
                    min_dist = distance[i];
                    min_index = i;
                }
            }
        }
        if(min_index != -1){
            start = min_index;
            visited[start] = true;
        }
    }
}

int main()
{
    int V, E, tempX, tempY;
    cin >> V >> E;
    int start = 0;
    bool * visited = new bool[V];
    int * distance = new int[V];
    int ** edge = new int*[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
        edge[i] = new int[V]();
        distance[i] = INT_MAX;
    }
    
    distance[start] = 0;
    for (int i = 0; i < E; i++)
    {
        int s, e, dist;
        cin>>s>>e>>dist;
        edge[s][e] = dist;
        edge[e][s] = dist;
    }
    
    solve(edge, start, V, visited, distance);

    for (int i = 0; i < V; i++)
    {
        cout<<i<<" "<<distance[i]<<endl;
    }
    delete [] visited;
    delete [] distance;
    for (int i = 0; i < V; i++)
    {
        delete [] edge[i];
    }
    delete [] edge;
    return 0;
}