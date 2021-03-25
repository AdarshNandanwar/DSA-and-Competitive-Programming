#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;

bool comparator(pair<ll, ll> a, pair<ll, ll> b){
    return (a.first+a.second) > (b.first+b.second);
}

void solve(){

    cin>>n;
    pair<ll, ll> * pairs = new pair<ll, ll>[n];
    for (ll i = 0; i < n; i++)
    {
        cin>>pairs[i].first;
    }
    for (ll i = 0; i < n; i++)
    {
        cin>>pairs[i].second;
    }
    sort(pairs, pairs+n, comparator);
    ll a_score = 0, b_score = 0;
    for (ll i = 0; i < n; i++)
    {
        if(i%2){
            b_score += pairs[i].second;
        } else {
            a_score += pairs[i].first;
        }
    }
    if(a_score > b_score){
        cout<<"First"<<endl;
    } else if(a_score < b_score){
        cout<<"Second"<<endl;
    } else {
        cout<<"Tie"<<endl;
    }

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