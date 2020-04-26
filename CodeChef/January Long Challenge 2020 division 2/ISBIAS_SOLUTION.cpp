#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, q;
    cin>>n>>q;
    ll * arr = new ll[n];
    for (ll i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    while(q--){
        ll l, r;
        cin>>l>>r;
        l--;r--;
        if((arr[l]<arr[l+1] && arr[r-1]<arr[r]) || (arr[l]>arr[l+1] && arr[r-1]>arr[r])){
            cout<<"NO\n";
        } else {
            cout<<"YES\n";
        }
    }
    
    delete [] arr;

    return 0;
}