#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;


void dfs(vector<string> & v, int n, int m, int x, int y){
    if(x<0 || n<=x || y<0 || m<=y){
        return;
    }
    if(v[x][y] == '.'){
        return;
    }
    v[x][y] = '.';
    vector<ll> X = {0, 1, 0, -1};
    vector<ll> Y = {1, 0, -1, 0};
    for(int i =0; i<4; i++){
        dfs(v, n, m, x+X[i], y+Y[i]);
    }
}


void solve(){

    ll m;
    cin>>n>>m;
    vector<string> v(n);
    for(int i = 0; i<n; i++){
        cin>>v[i];
    }

    vector<bool> placed_x(n, false);
    vector<bool> placed_y(m, false);

    for(int i = 0; i<n; i++){
        bool black_found = false;
        bool white_after_black_found = false;
        for(int j = 0; j<m; j++){
            if(v[i][j] == '#'){
                if(white_after_black_found){
                    cout<<-1<<endl;
                    return;
                }
                placed_y[j] = true;
                black_found = true;
            } else {
                if(black_found){
                    white_after_black_found = true;
                }
            }
        }
    }

    for(int i = 0; i<m; i++){
        bool black_found = false;
        bool white_after_black_found = false;
        for(int j = 0; j<n; j++){
            if(v[j][i] == '#'){
                if(white_after_black_found){
                    cout<<-1<<endl;
                    return;
                }
                placed_x[j] = true;
                black_found = true;
            } else {
                if(black_found){
                    white_after_black_found = true;
                }
            }
        }
    }

    ll count_x = 0, count_y = 0;
    for(int i =0; i<n; i++){
        if(!placed_x[i]) count_x++;
    }
    for(int i =0; i<m; i++){
        if(!placed_y[i]) count_y++;
    }
    if((count_x>0)^(count_y>0)){
        cout<<-1<<endl;
        return;
    }

    ll count = 0;
    for(int i =0; i<n; i++){
        for(int j =0; j<m; j++){
            if(v[i][j] == '#'){
                dfs(v, n, m, i, j);
                count++;
            }
        }
    }
    cout<<count<<endl;
}
 
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 1;
    while(t--){
        solve();
    }
    return 0;
}