#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;

bool comparator(pair<ll, ll> a, pair<ll, ll> b){
    return a.second > b.second;
}

void solve(){

    ll k;
    cin>>n>>k;
    k--;
    ll * num = new ll[n];
    pair<ll, ll> * arr = new pair<ll, ll>[n];
    for (ll i = 0; i < n; i++)
    {
        cin>>num[i];
    }
    
    for (ll i = 1; i < n; i++)
    {
        arr[i].first = i;
        arr[i].second = num[i] - num[i-1];
    }
    vector<pair<ll, ll>> v;
    sort(arr+1, arr+n, comparator);
    for (ll i = 1; i <= k; i++)
    {
        v.push_back(arr[i]);
    }
    sort(v.begin(), v.end());
    ll start = 0, cost = 0;
    for (auto itr = v.begin(); itr != v.end(); itr++)
    {
        cost += (num[itr->first - 1] - num[start]);
        start = itr->first;
    }
    cost += (num[n-1]-num[start]);
    cout<<cost<<endl;

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