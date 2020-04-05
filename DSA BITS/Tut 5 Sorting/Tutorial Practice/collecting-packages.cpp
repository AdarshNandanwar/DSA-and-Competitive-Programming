#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;

bool comparator(pair<ll, ll> a, pair<ll, ll> b){
    if(a.first != b.first){
        return a.first < b.first;
    } else {
        return a.second < b.second;
    }
}

void solve(){

    cin>>n;
    pair<ll, ll> * pairs = new pair<ll, ll>[n+1];
    pairs[0] = {0,0};
    for (ll i = 1; i <= n; i++)
    {
        cin>>pairs[i].first>>pairs[i].second;
    }
    sort(pairs+1, pairs+1+n, comparator);
    for (ll i = 1; i <= n; i++)
    {
        if(pairs[i].first < pairs[i-1].first || pairs[i].second < pairs[i-1].second){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 0; j < pairs[i].first-pairs[i-1].first; j++)
        {
            cout<<'R';
        }
        for (ll j = 0; j < pairs[i].second-pairs[i-1].second; j++)
        {
            cout<<'U';
        }
    }
    cout<<endl;        
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