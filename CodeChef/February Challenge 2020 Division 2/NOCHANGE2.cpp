#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;

void solve(){

    ll p, i;
    cin>>n>>p;
    ll * arr = new ll[n]();
    ll * orig = new ll[n]();
    map<ll, ll> m;
    for (ll i = 0; i < n; i++)
    {
        cin>>arr[i];
        orig[i] = arr[i];
        m[arr[i]] = 0;
    }
    bool flag = false;
    sort(arr, arr+n, greater<ll>());
    for (i = 0; i < n; i++)
    {
        if(i){
            if(arr[i-1]%arr[i] != 0){
                ll temp = p/arr[i-1] - 1;
                m[arr[i-1]] = temp;
                temp = (p-(temp*arr[i-1]))/arr[i]+1;
                m[arr[i]] = temp;
                flag = true;
                break;
            }
        } else {
            if(p%arr[i] != 0){
                m[arr[i]] = p/arr[i]+1;
                flag = true;
                break;
            }
        }
    }
    if(flag){
        cout<<"YES ";
        for (ll i = 0; i < n; i++)
        {
            cout<<m[orig[i]]<<" ";
        }
        cout<<endl;
    } else {
        cout<<"NO\n";
    }
    

    delete [] arr;
    delete [] orig;
    return;
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