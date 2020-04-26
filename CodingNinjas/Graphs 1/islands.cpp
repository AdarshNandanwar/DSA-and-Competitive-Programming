// Islands
// Send Feedback
// An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . Given N islands (numbered from 1 to N) and two lists of size M (u and v) denoting island u[i] is connected to island v[i] and vice versa . Can you count the number of connected groups of islands.
// Constraints :
// 1<=N<=100
// 1<=M<=(N*(N-1))/2
// 1<=u[i],v[i]<=N
// Input Format :
// Line 1 : Two integers N and M
// Line 2 : List u of size of M
// Line 3 : List v of size of M
// Output Return Format :
// The count the number of connected groups of islands
// Sample Input :
// 2 1
// 1
// 2
// Sample Output :
// 1 

#include<bits/stdc++.h>
using namespace std;

void traverse(bool ** edge, int n, int sv, bool * visited){
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if(edge[sv][i] && !visited[i]){
            traverse(edge, n, i, visited);
        }
    }
    
}

int solve(int n,int m,vector<int>u,vector<int>v)
{
	int count = 0;
    bool * visited = new bool[n];
    bool ** edge = new bool*[n];
    for (int i = 0; i < n; i++)
    {
        edge[i] = new bool[n];
        for (int j = 0; j < n; j++)
        {
            edge[i][j] = false;
        }
        visited[i] = false;
    }
    for (int i = 0; i < m; i++)
    {
        edge[u[i]-1][v[i]-1] = true;
        edge[v[i]-1][u[i]-1] = true;
    }
    

    for (int i = 0; i < n; i++)
    {
        if(!visited[i]){
            count++;
            traverse(edge, n, i, visited);
        }
    }

    for (int i = 0; i < n; i++)
    {
        delete [] edge[i];
    }
    delete [] edge;
    delete [] visited;
    return count;
}

int main(){
    int n, m, a;
    cin>>n>>m;
    vector<int> u;
    vector<int> v;

    for (int i = 0; i < m; i++)
    {
        cin>>a;
        u.push_back(a);
    }
    for (int i = 0; i < m; i++)
    {
        cin>>a;
        v.push_back(a);
    }
    cout<<solve(n, m, u, v)<<endl;
    
    return 0;
}