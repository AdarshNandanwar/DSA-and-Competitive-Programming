#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, sum = 0, count0 = 0;
        cin>>n;
        ll * arr = new ll[n];
        for (ll i = 0; i < n; i++)
        {
            cin>>arr[i];
            sum+=arr[i];
            if(!arr[i]){
                count0++;
            }
        }
        sum += count0;
        if(!sum){
            count0 ++;
        }
        cout<<count0<<endl;    
    }
    return 0;
}