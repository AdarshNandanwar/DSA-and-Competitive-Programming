// Code : Get Path - DFS
// Send Feedback
// Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
// Find the path using DFS and print the first path that you encountered.
// V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
// E is the number of edges present in graph G.
// Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
// Note : Save the input graph in Adjacency Matrix.
// Input Format :
// Line 1: Two Integers V and E (separated by space)
// Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
// Line (E+2) : Two integers v1 and v2 (separated by space)
// Output Format :
// Path from v1 to v2 in reverse order (separated by space)
// Constraints :
// 2 <= V <= 1000
// 1 <= E <= 1000
// 0 <= v1, v2 <= V-1
// Sample Input 1 :
// 4 4
// 0 1
// 0 3
// 1 2
// 2 3
// 1 3
// Sample Output 1 :
// 3 0 1
// Sample Input 2 :
// 6 3
// 5 3
// 0 1
// 3 4
// 0 3
// Sample Output 2 :

#include <iostream>
using namespace std;

bool has_path_DSF(bool ** edge, int n, int sv, bool * visited, int ev){
    visited[sv] = true;
    if(sv == ev){
        cout<<sv<<" ";
        return true;
    }
    for (int i = 0; i < n; i++)
    {
        if(sv == i){
            continue;
        }
        if(edge[sv][i]){
            if(i == ev){
                cout<<ev<<" ";
                return true;
            }
            if(visited[i]){
                continue;
            } else {
                bool ans = has_path_DSF(edge, n, i, visited, ev);
                if(ans){
                    cout<<i<<" ";
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    int V, E;
    cin >> V >> E;
    bool * visited = new bool[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }
    bool ** edge = new bool*[V];
    for (int i = 0; i < V; i++)
    {
        edge[i] = new bool[V];
        for (int j = 0; j < V; j++)
        {
            edge[i][j] = false;
        }
    }
    for (int i = 0; i < E; i++)
    {
        int a, b;
        cin>>a>>b;
        edge[a][b] = true;
        edge[b][a] = true;
    }
    int v1, v2;
    cin>>v1>>v2;
    if(has_path_DSF(edge, V, v1, visited, v2)){
        cout<<v1<<"\n";
    }
    for (int i = 0; i < V; i++)
    {
        delete [] edge[i];
    }
    delete [] visited;
    delete [] edge;
    return 0;
}