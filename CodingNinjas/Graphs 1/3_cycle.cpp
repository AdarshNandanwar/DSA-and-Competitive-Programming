// 3 Cycle
// Send Feedback
// Given a graph with N vertices and Two Lists (U,V) of size M where (U[i],V[i]) and (V[i],U[i]) are connected by an edge , then count the distinct 3-cycles in the graph. A 3-cycle PQR is a cycle in which (P,Q), (Q,R) and (R,P) are connected an edge.
// Input Format :
// Line 1 : Two integers N and M
// Line 2 : List u of size of M
// Line 3 : List v of size of M
// Return Format :
// The count the number of 3-cycles in the given Graph
// Constraints :
// 1<=N<=100
// 1<=M<=(N*(N-1))/2
// 1<=u[i],v[i]<=N
// Sample Input:
// 3 3
// 1 2 3
// 2 3 1
// Sample Output:
// 1

#include<bits/stdc++.h>
using namespace std;

int helper(int ** edge, int n, int sv, bool * visited){
    int count = 0;
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        if(sv == i){
            continue;
        }
        if(edge[i][sv] && !visited[i]){
            visited[i] = 1;
            temp.push_back(i);
            for (int j = 0; j < n; j++)
            {
                if(j == i || j == sv){
                    continue;
                }
                if(edge[j][i] && edge[sv][j] && !visited[j]){
                    // don't do visited
                    count++;
                }
            }          
        }
    }
    for (int i = 0; i < temp.size(); i++)
    {
        visited[temp[i]] = 0;
    }
    return count;
}

int solve(int n,int m,vector<int>u,vector<int>v)
{
	// Write your code here .
    int ans = 0;
    int ** edge = new int*[n];
    bool * visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        edge[i] = new int[n]();
    }
    for (int i = 0; i < m; i++)
    {
        edge[u[i]-1][v[i]-1] = 1;
        edge[v[i]-1][u[i]-1] = 1;
    }
    
    for (int i = 0; i < n; i++)
    {
        if(!visited[i]){
            visited[i] = 1;
            ans += helper(edge, n, i, visited);
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        delete [] edge[i];
    }
    delete [] edge;
    delete [] visited;
    return ans;
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
    int ans;
    ans = solve(n, m, u, v);
    cout<<ans;
    return 0;
}