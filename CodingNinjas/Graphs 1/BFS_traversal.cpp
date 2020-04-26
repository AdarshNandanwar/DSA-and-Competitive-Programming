// Code : BFS Traversal
// Send Feedback
// Given an undirected and connected graph G(V, E), print its BFS traversal.
// Here you need to consider that you need to print BFS path starting from vertex 0 only.
// V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
// E is the number of edges present in graph G.
// Input Format :
// Line 1: Two Integers V and E (separated by space)
// Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.
// Output Format :
// BFS Traversal (separated by space)
// Constraints :
// 2 <= V <= 1000
// 1 <= E <= 1000
// Sample Input 1:
// 4 4
// 0 1
// 0 3
// 1 2
// 2 3
// Sample Output 1:
// 0 1 3 2

#include <iostream>
#include<queue>
using namespace std;

void print(bool ** edge, int n, queue<int> q, bool * visited){
    if(q.empty()){
        return;
    }
    cout<<q.front()<<" ";
    for (int i = 0; i < n; i++)
    {
        if(q.front() == i){
            continue;
        }
        if(edge[q.front()][i]){
            if(visited[i]){
                continue;
            } else {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    q.pop();
    print(edge, n, q, visited);
}

int main() {
    int V, E;
    cin >> V >> E;
    queue<int> q;
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
    q.push(0);
    visited[0] = true;
    print(edge, V, q, visited);
    for (int i = 0; i < V; i++)
    {
        delete [] edge[i];
    }
    delete [] visited;
    delete [] edge;
    return 0;
}
