#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, d, m;
    cin>>n>>d>>m;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    ll count = 0;
    ll sum = 0;
    if(m<=n){
        for (ll i = 0; i < m; i++)
        {
            sum+=arr[i];
        }
        if(sum == d) count++;
        for (ll i = m; i < n; i++)
        {
            sum = sum + arr[i] - arr[i-m];
            if(d == sum) count++;
        }
        
        cout<<count<<endl;
        
    }

    return 0;
    
}