#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

class Solution {
public:
    
    vector<int> dir = {0, 1, 0, -1, 0};
    
    bool helper_pacific(vector<vector<int>>& matrix, int i, int j, vector<vector<int>> & visited){
        int n = matrix.size(), m = matrix[0].size();
            
        if(visited[i][j] != -1) return visited[i][j];
        visited[i][j] = 0;
        
        for(int k = 0; k<4; k++){
            int next_i = i+dir[k], next_j = j+dir[k+1];
        
            if(next_i == -1 or next_j == -1) visited[i][j] = 1;
            if(next_i == n or next_j == m) continue;
            
            if(matrix[next_i][next_j] <= matrix[i][j] and helper_pacific(matrix, next_i, next_j, visited)) visited[i][j] = 1;
        }
        
        return visited[i][j];
    }
    
    bool helper_atlantic(vector<vector<int>>& matrix, int i, int j, vector<vector<int>> & visited){
        int n = matrix.size(), m = matrix[0].size();
            
        if(visited[i][j] != -1) return visited[i][j];
        visited[i][j] = 0;
        
        for(int k = 0; k<4; k++){
            int next_i = i+dir[k], next_j = j+dir[k+1];
        
            if(next_i == -1 or next_j == -1) continue;
            if(next_i == n or next_j == m) visited[i][j] = 1;
            
            if(matrix[next_i][next_j] <= matrix[i][j] and helper_atlantic(matrix, next_i, next_j, visited)) visited[i][j] = 1;
        }
        
        return visited[i][j];
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n <= 0) return {};
        int m = matrix[0].size();
        
        vector<vector<int>> ans;
        
        // PACIFIC
        vector<vector<int>> visited_pacific(n, vector<int>(m, -1));
        // -1: unvisited, 0: visited, 1: reaches pacific
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                helper_pacific(matrix, i, j, visited_pacific);
            }
        }
        
        // ATLANTIC
        vector<vector<int>> visited_atlantic(n, vector<int>(m, -1));
        // -1: unvisited, 0: visited, 1: reaches atlantic
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                helper_atlantic(matrix, i, j, visited_atlantic);
            }
        }
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                cout<<visited_pacific[i][j]<<" ";
            }
            cout<<endl;
        }
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                cout<<visited_atlantic[i][j]<<" ";
            }
            cout<<endl;
        }
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(visited_pacific[i][j] == 1 and visited_atlantic[i][j] == 1) ans.push_back({i,j});
            }
        }
        
        
        return ans;
    }
};

void solve(){

    cout<<stoi("11111111111155555555")<<endl;


    n =5;
    map<int, list<int>::iterator> m;
    list<int> ll;
    for(int i=1; i<=n; i++){
        ll.push_front(i);
        m[i] = ll.begin();
    }

    for(auto i:ll){
        cout<<i<<" ";
    } cout<<endl;

    for(auto i:m){
        cout<<i.first<<" "<<*(i.second)<<endl;
    }

    cout<<endl;

    auto it = ll.begin();
    it = next(it);
    ll.insert(it, 6);
    m[6] = prev(it);

    for(auto i:ll){
        cout<<i<<" ";
    } cout<<endl;

    for(auto i:m){
        cout<<i.first<<" "<<*(i.second)<<endl;
    }

    cout<<endl;

}
 
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cout<<LLONG_MAX<<endl;
    return 0;
}