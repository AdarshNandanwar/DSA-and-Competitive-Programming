//Minimum time to rot all oranges
 
#include<bits/stdc++.h>
using namespace std;
 
bool isDelim(pair<int, int> p1, pair<int, int> p2){
    if(p1.first == p2.first && p1.second == p2.second)
        return true;
    return false;
}
 
bool allRotten(vector<vector<int>> oranges){
    for(int i=0; i<oranges.size(); i++){
        for(int j=0; j<oranges[i].size(); j++){
            if(oranges[i][j] == 1)
                return false;
        }
    }
    return true;
}
 
int findTotalTime(vector<vector<int>> oranges, int n, int m)
{
    queue<pair<int, int>> q;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(oranges[i][j] == 2)
                q.push(make_pair(i, j));
        }
    }
 
    q.push({-1, -1});
 
    int time = 0;
 
    while(!q.empty()){
        bool flag = false;
        while(!isDelim(q.front(), {-1, -1})){
            pair<int, int> temp = q.front();
            int x = temp.first;
            int y = temp.second;
 
            if(((x+1) < n && y < m) && oranges[x+1][y] == 1){
                if(!flag){
                    flag = true;
                    time++;
                }
 
                oranges[x+1][y] = 2;
                q.push({x+1, y});
            }
 
            if((x < n && (y+1) < m) && oranges[x][y+1] == 1){
                if(!flag){
                    flag = true;
                    time++;
                }
 
                oranges[x][y+1] = 2;
                q.push({x, y+1});
            }
 
            if(((x-1) >= 0 && y < m) && oranges[x-1][y] == 1){
                if(!flag){
                    flag = true;
                    time++;
                }
 
                oranges[x-1][y] = 2;
                q.push({x-1, y});
            }
 
            if((x < n && (y-1) >= 0) && oranges[x][y-1] == 1){
                if(!flag){
                    flag = true;
                    time++;
                }
 
                oranges[x][y-1] = 2;
                q.push({x, y-1});
            }
            q.pop();
        }
        q.pop();
 
        if(!q.empty()){
            q.push({-1, -1});
        }
    
    }
 
    if(allRotten(oranges))
        return time;
    return -1;
 
}
 
int main(){
    int n, m;
    cin>>n>>m;
    
    vector<vector<int>> oranges(n);
 
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int x;
            cin>>x;
            oranges[i].push_back(x);
        }
    }
 
    cout<<findTotalTime(oranges, n, m)<<endl;
}