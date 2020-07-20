#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

void solve(){

    ll m;
    pair<ll,ll> maxSec = {INT_MAX,INT_MIN};
    cin>>n>>m;
    vector<pair<ll,ll>> v;
    for(ll i = 0; i<m; i++){
        ll a, b;
        cin>>a>>b;
        v.push_back({a, b});
        if(maxSec.second <= b and maxSec.first > a) maxSec = {a, b};
    }
    ll res = 0;
    sort(v.begin(), v.end(), [](const pair<ll, ll> & a, const pair<ll, ll> & b){
        return a.first == b.first ? a.second > b.second : a.first > b.first;
    });

    bool isDone = 0;
    for(int i = 0; i<m; i++){
        if(n <= 0) break;
        if(v[i] == maxSec) {
            res += v[i].first;
            isDone = 1;
        } else {
            if(v[i].first + (isDone ? (max(n-1, 0ll))*maxSec.second : maxSec.first+(max(n-2, 0ll))*maxSec.second) > 
            (isDone ? n*maxSec.second : maxSec.first+(max(n-1, 0ll))*maxSec.second)) {
                res += v[i].first;
            } else {
                res += ((isDone?(n)*maxSec.second:maxSec.first+(max(n-1, 0ll))*maxSec.second));
                n = 0;
            }
        }
        n--;
    }
    if(n > 0) res += ((isDone?(n)*maxSec.second:maxSec.first+(max(n-1, 0ll))*maxSec.second));
    cout<<res<<endl;

}
 
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}