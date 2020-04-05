#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n, m;
    cin>>n>>m;
    ll * start = new ll[n]();
    ll * end = new ll[n]();
    while(m--){
        ll s, e, val;
        cin>>s>>e>>val;
        start[s-1]+=val;
        end[e-1]+=val;
    }
    for (ll i = 1; i < n; i++)
    {
        start[i]+=start[i-1];
        end[i]+=end[i-1];
    }
    for (ll i = 1; i < n; i++)
    {
        start[i]-=end[i-1];
    }
    ll mx = 0;
    for (ll i = 0; i < n; i++)
    {
        mx=max(mx, start[i]);
    }
    cout<<mx<<endl;
    return 0;
}