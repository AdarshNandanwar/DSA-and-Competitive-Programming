#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

void solve(){
    ll t;
    cin>>n;
    vector<ll> inc, dec;
    unordered_map<ll, ll> freq;
    bool valid = true;
    for(int i = 0; i<n; i++){
        cin>>t;
        freq[t]++;
        if(freq[t] == 1) {
            dec.push_back(t);
        } else if(freq[t] == 2){
            inc.push_back(t);
        } else {
            valid = false;
        }
    } 
    if(valid){
        cout<<"YES\n";
        sort(inc.begin(), inc.end());
        sort(dec.begin(), dec.end(), greater<ll>());
        cout<<inc.size()<<endl;
        for(auto i:inc) cout<<i<<" ";
        cout<<endl;
        cout<<dec.size()<<endl;
        for(auto i:dec) cout<<i<<" ";
        cout<<endl;
    } else {
        cout<<"NO\n";
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