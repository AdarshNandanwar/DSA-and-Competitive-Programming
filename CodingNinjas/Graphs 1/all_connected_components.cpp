// Code : All connected components
// Send Feedback
// Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
// V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
// E is the number of edges present in graph G.
// You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.
// Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.
// Input Format :
// Line 1: Two Integers V and E (separated by space)
// Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.
// Output Format :
// Different components in new line
// Constraints :
// 2 <= V <= 1000
// 1 <= E <= 1000
// Sample Input 1:
// 4 2
// 0 1
// 2 3
// Sample Output 1:
// 0 1 
// 2 3 
// Sample Input 2:
// 4 3
// 0 1
// 1 3 
// 0 3
// Sample Output 2:
// 0 1 3 
// 2

#include<bits/stdc++.h>
using namespace std;

void traverse(bool ** edge, int n, int sv, bool * visited, vector<int> & ans){
    visited[sv] = true;
    ans.push_back(sv);
    for (int i = 0; i < n; i++)
    {
        if(edge[sv][i] && !visited[i]){
            traverse(edge, n, i, visited, ans);
        }
    }
    
}

int main()
{
    int V, E, tempX, tempY;
    cin >> V >> E;

    bool * visited = new bool[V];
    bool ** edge = new bool*[V];
    for (int i = 0; i < V; i++)
    {
        edge[i] = new bool[V];
        for (int j = 0; j < V; j++)
        {
            edge[i][j] = false;
        }
        visited[i] = false;
    }
    
    for (int i = 0; i < E; i++)
    {
        int a, b;
        cin>>a>>b;
        edge[a][b] = true;
        edge[b][a] = true;
    }
    
    for (int i = 0; i < V; i++)
    {
        if(!visited[i]){
            vector<int> ans;
            traverse(edge, V, i, visited, ans);
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++)
            {
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }
    }

    for (int i = 0; i < V; i++)
    {
        delete [] edge[i];
    }
    delete [] edge;
    delete [] visited;
    return 0;
}
