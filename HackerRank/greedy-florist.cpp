#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, k, cost = 0;
    cin>>n>>k;
    ll * arr = new ll[n];
    for (ll i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    sort(arr, arr+n);
    reverse(arr, arr+n);
    ll modulo = n%k;
    ll groups = n/k;
    for (ll i = 0; i < groups; i++)
    {
        for (ll j = 0; j < k; j++)
        {
            cost += ((i+1)*arr[i*k+j]);
        }
        
    }
    for (ll i = (n/k)*k; i < n; i++)
    {
        cost += ((groups+1)*arr[i]);
    }
    
    cout<<cost<<endl;
    return 0;
}