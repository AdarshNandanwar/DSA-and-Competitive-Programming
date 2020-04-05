#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, ans = 0;
        cin>>n;
        ll * arr = new ll[n];
        for (ll i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        
        if(n%2){
            for (ll i = 0; i < n; i += 2)
            {
                ans ^= arr[i];
            }
            cout<<ans<<endl;
        } else {
            cout<<0<<endl;
        }
        delete [] arr;
    }
    

    return 0;
}