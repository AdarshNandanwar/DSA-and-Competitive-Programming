#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

string final_ans;

void getNum(string & s, int k, vector<pair<ll, ll>> & ans){
    vector<string> seq = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
    reverse(seq.begin(), seq.end());
    int j =0, count = 0;
    for(int i =0; i<10; i++){
        count = 0;
        for(j = 0; j<7; j++){
            if(s[j] == '0'){
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
            ans.push_back({9-i, count});
        }
    }
}

void helper(vector<string> & v, ll n, ll k, ll index, string ans, bool & done, vector<vector<bool>> & dp){

    if(k<0){
        return;
    }
    if(ans.length() == n && k == 0){
        final_ans = ans;
        done = true;
        return;
    }
    if(index>=n){
        return;
    }

    if(dp[index][k]){
        return;
    }

    vector<pair<ll,ll>> opt;
    getNum(v[index], k, opt);
        
    for(int i = 0; i<opt.size(); i++){
        helper(v, n, k-opt[i].second, index+1, ans+to_string(opt[i].first), done, dp);
        if(done){
            return;
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
    string ans = "";
    vector<vector<bool>> dp(n+1, vector<bool>(k+1, false));
    
    helper(v, n, k, 0, ans, done, dp);
    if(done){
        cout<<final_ans<<endl;
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