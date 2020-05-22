#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

vector<string> seq = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
ll n;
 
void helper(vector<string> & v, ll n, ll k, ll index, vector<int> & ans, bool & done, vector<vector<bool>> & dp){
 
    if(ans.size() == n && k == 0){
        done = true;
        return;
    }
    if(index>=n || k<0){
        return;
    }
 
    if(dp[index][k]){
        return;
    }
    
    for(ll i = 9; i>=0; i--){
        ll count = 0, j;
        for(j = 0; j<7; j++){
            if(v[index][j] == '0'){
                if(seq[i][j] == '1'){
                    if(count >= k ){
                        break;
                    }
                    count++;
                }
            } else {
                if(seq[i][j] == '0'){
                    break;
                }
            }
        }
        if(j == 7){
            ans.push_back(i);
            helper(v, n, k-count, index+1, ans, done, dp);
            ans.pop_back();        
            if(done){
                return;
            }
        }
    }

    dp[index][k] = true;
}
 
void solve(){
 
    ll k;
    cin>>n>>k;
    vector<string> v(n);
    for(int i = 0; i<n; i++){
        cin>>v[i];
    }
 
    bool done = false;
    vector<int> ans;
    vector<vector<bool>> dp(n+1, vector<bool>(k+1, false));
    
    helper(v, n, k, 0, ans, done, dp);
    if(done){
        for(ll i =0; i<n; i++){
            cout<<ans[i];
        }
        cout<<endl;
    } else {
        cout<<-1<<endl;
    }
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