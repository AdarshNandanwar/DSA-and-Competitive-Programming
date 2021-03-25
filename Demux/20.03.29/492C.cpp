#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

bool comp(pair<ll, ll> a, pair<ll, ll> b){
    return a.second < b.second;
}

void solve(){
    ll r, avg, count = 0;
    cin>>n>>r>>avg;
    ll req_sum = avg*n, curr_sum = 0;
    pair<ll, ll> * a = new pair<ll, ll>[n];
    for(ll i = 0; i<n ; i++){
        cin>>a[i].first>>a[i].second;
        curr_sum+=a[i].first;
    }
    sort(a, a+n, comp);
    ll i = 0;
    while(req_sum-curr_sum > 0){
        if(curr_sum+(r-a[i].first) < req_sum){
            curr_sum += (r-a[i].first);
            count += ((r-a[i].first)*a[i].second);
            i++;
        } else {
            count += (req_sum-curr_sum)*a[i].second;
            break;
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