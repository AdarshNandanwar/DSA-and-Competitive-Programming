// Kruskal's Algorithm
// Send Feedback
// Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
// Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
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

class EdgeClass {
    public:
    int start;
    int end;
    int weight;
};

bool compare(EdgeClass a, EdgeClass b){
    if(a.weight != b.weight){
        return a.weight < b.weight;
    } else {
        if(a.start != b.start){
            return a.start < b.start;
        } else {
            return a.end < b.end;
        }
    }
}

int find_parent(int a, int * parent){
    while(a != parent[a]){
        a = parent[a];
    }
    return a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int V, E, tempX, tempY;
    cin >> V >> E;

    /*

        Write Your Code Here
        Complete the Rest of the Program
        You have to Print the output yourself
        
    */

    EdgeClass * edge = new  EdgeClass[E];
    for (int i = 0; i < E; i++)
    {
        cin>>edge[i].start>>edge[i].end>>edge[i].weight;
    }
    sort(edge, edge+E, compare);
    int * parent = new int[V];;
    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
    }
    
    EdgeClass ans[V-1];
    int count = 0, i=0;
    while(count<V-1){
        int a = edge[i].start, b = edge[i].end;
        int a_parent = find_parent(a, parent), b_parent = find_parent(b, parent);
        if(a_parent != b_parent){
            parent[b_parent] = a;
            ans[count] = edge[i];
            count++;
        }
        i++;
    }
    for (int i = 0; i < V-1; i++)
    {
        if(ans[i].start < ans[i].end){
            cout<<ans[i].start<<" "<<ans[i].end<<" "<<ans[i].weight<<endl;
        } else {
            cout<<ans[i].end<<" "<<ans[i].start<<" "<<ans[i].weight<<endl;
        }
    }
    delete [] edge;
    return 0;
}
