// Code : Get Path - BFS
// Send Feedback
// Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
// Find the path using BFS and print the shortest path available.
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
#include<queue>
#include<map>
using namespace std;

vector<int> get_path_BFS(bool ** edge, int n, int sv, bool * visited, int ev){
    queue<int> q;
    vector<int> path;
    map<int, int> m;
    q.push(sv);
    while(!q.empty()){
        int current = q.front();
        q.pop();
        if(current == ev){
            int temp = current;
            while(temp != sv){
                path.push_back(temp);
                temp = m[temp];
            }
            path.push_back(temp);
        }
        for (int i = 0; i < n; i++)
        {
            if(i == current){
                continue;
            }
            if(edge[current][i] && !visited[i]){
                q.push(i);
                m[i] = current;
                visited[i] = true;
            }
        }
        
    }
    return path;
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
    vector<int> path = get_path_BFS(edge, V, v1, visited, v2);
    for (int i = 0; i < path.size(); i++)
    {
        cout<<path[i]<<" ";
    }
    cout<<endl;
    
    for (int i = 0; i < V; i++)
    {
        delete [] edge[i];
    }
    delete [] visited;
    delete [] edge;
    return 0;
}