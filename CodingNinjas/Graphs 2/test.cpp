#include <bits/stdc++.h>
using namespace std;

void solve(int ** edge, int start, int V, bool * visited, int * distance, vector<int> unvisited){
    int n = V-1;
    visited[start] = true;
    while(n--){
        int min_dist = INT_MAX, min_index = -1;
        for (int i = 0; i < unvisited.size(); i++)
        {
            if(edge[start][unvisited[i]] && !visited[unvisited[i]]){
                int temp = edge[start][unvisited[i]] + distance[start];
                if(temp < distance[unvisited[i]]){
                    distance[unvisited[i]] = temp;
                }
                if(min_dist > distance[unvisited[i]]){
                    min_dist = distance[unvisited[i]];
                    min_index = i;
                }
            }
        }
        if(min_index != -1){
            start = unvisited[min_index];
            visited[min_index] = true;
            unvisited.erase(unvisited.begin() + min_index);
        }
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int V, E, tempX, tempY;
        cin >> V >> E;

        /*

            Write Your Code Here
            Complete the Rest of the Program
            You have to Print the output yourself
            
        */

        int start = 0;
        bool * visited = new bool[V];
        vector<int> unvisited;
        int * distance = new int[V];
        int ** edge = new int*[V];
        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
            edge[i] = new int[V]();
        }
        
        for (int i = 0; i < E; i++)
        {
            int s, e, dist;
            cin>>s>>e>>dist;
            edge[s][e] = dist;
            edge[e][s] = dist;
        }
        cin>>start;
        distance[start] = 0;
        for (int i = 0; i < V; i++)
        {
            if(i != start){
                unvisited.push_back(i);
            }
            distance[i] = INT_MAX;
        }
        solve(edge, start, V, visited, distance, unvisited);

        for (int i = 0; i < V; i++)
        {
            cout<<distance[i]<<" ";
        }cout<<endl;
        

        delete [] visited;
        delete [] distance;
        for (int i = 0; i < V; i++)
        {
            delete [] edge[i];
        }
        delete [] edge;
    }
    
    return 0;
}