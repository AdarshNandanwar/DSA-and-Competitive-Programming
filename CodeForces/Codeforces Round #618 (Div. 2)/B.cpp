#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll * arr  =new ll[2*n];
        for (ll i = 0; i < 2*n; i++)
        {
            cin>>arr[i];
        }
        sort(arr, arr+2*n);
        cout<<arr[n]-arr[n-1]<<endl;
    }
    return 0;
}