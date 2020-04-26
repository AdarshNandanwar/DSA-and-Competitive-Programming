// Prim's Algorithm
// Send Feedback
// Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
// Find and print the Minimum Spanning Tree (MST) using Prim's algorithm.
// For printing MST follow the steps -
// 1. In one line, print an edge which is part of MST in the format -
// v1 v2 w
// where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1 <= v2 i.e. print the smaller vertex first while printing an edge.
// 2. Print V-1 edges in above format in different lines.
// Note : Order of different edges doesn't matter.
// Input Format :
// Line 1: Two Integers V and E (separated by space)
// Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
// Output Format :
// MST
// Constraints :
// 2 <= V, E <= 10^5
// Sample Input 1 :
// 4 4
// 0 1 3
// 0 3 5
// 1 2 1
// 2 3 8
// Sample Output 1 :
// 1 2 1
// 0 1 3
// 0 3 5

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int V, E, tempX, tempY;
    cin >> V >> E;

    /*

        Write Your Code Here
        Complete the Rest of the Program
        You have to Print the output yourself
        
    */
    // EdgeClass * edge = new  EdgeClass[E];
    int ** branch = new int*[V];
    for (int i = 0; i < V; i++)
    {
        branch[i] = new int[V]();
    }
    
    for (int i = 0; i < E; i++)
    {
        int start, end, weight;
        cin>>start>>end>>weight;
        branch[start][end] = weight;
        branch[end][start] = weight;
    }
    bool * visited = new bool[V];    
    int * parent = new int[V];
    int * weight = new int[V];
    vector<int> unvisited;
    for (int i = 1; i < V; i++)
    {
        unvisited.push_back(i);        
    }
    
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
        parent[i] = -1;
        weight[i] = INT_MAX;
    }
    weight[0] = 0;
    int pos = 0, i=0;
    visited[0] = true;
    while(!unvisited.empty())
    {
        // cout<<"pos:"<<pos<<endl;
        // for (int i = 0; i < V; i++)
        // {
        //     cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
        // }
        // for (int j = 0; j < unvisited.size(); j++)
        // {
        //     cout<<unvisited[j]<<" ";
        // }cout<<endl;

        int min_weight = INT_MAX, min_weight_index;
        for (int j = 0; j < V; j++)
        {
            if(branch[pos][j] && !visited[j]){
                if(weight[j] > branch[pos][j]){
                    weight[j] = branch[pos][j];
                    parent[j] = pos;
                }
            }
        }
        int min_index_in_unvisited;
        for (int j = 0; j < unvisited.size(); j++)
        {
            if(min_weight > weight[unvisited[j]]){
                min_weight = weight[unvisited[j]];
                min_weight_index = unvisited[j];
                min_index_in_unvisited = j;
            }
        }
        pos = min_weight_index;
        visited[pos] = true;
        unvisited.erase(unvisited.begin() + min_index_in_unvisited);
        i++;
        // cout<<"after: "<<endl;
        // cout<<"pos:"<<pos<<endl;
        // for (int i = 0; i < V; i++)
        // {
        //     cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
        // }
        // for (int j = 0; j < unvisited.size(); j++)
        // {
        //     cout<<unvisited[j]<<" ";
        // }cout<<endl;
        // cout<<"==================="<<endl;
    }
    for (int i = 1; i < V; i++)
    {
        if(i < parent[i]){
            cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
        } else {
            cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
        }
    }
    

    return 0;
}
