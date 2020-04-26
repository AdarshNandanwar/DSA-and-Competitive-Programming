#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin>>n;
    vector<ll> X, Y;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin>>x;
        X.push_back(x);
    }
    for (ll i = 0; i < n; i++)
    {
        ll y;
        cin>>y;
        Y.push_back(y);
    }
    Y.push_back(0);
    Y.push_back(200);
    sort(Y.begin(),Y.end());
    ll max_width = INT_MIN;
    for (ll i = 1; i < Y.size(); i++)
    {
        max_width = max(max_width, Y[i]-Y[i-1]);
    }
    cout<<max_width-1<<endl;
    
    return 0;
}