#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin>>n;
    ll * arr = new ll[n];
    ll * fwd = new ll[n];
    ll * bwd = new ll[n];

    for (ll i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    fwd[0] = 1;
    for (ll i = 1; i < n; i++)
    {
        if(arr[i] > arr[i-1]){
            fwd[i] = fwd[i-1]+1;
        } else {
            fwd[i] = 1;
        }
    }

    bwd[n-1] = 1;
    for (ll i = n-2; i >= 0; i--)
    {
        if(arr[i+1] < arr[i]){
            bwd[i] = bwd[i+1]+1;
        } else {
            bwd[i] = 1;
        }
    }
    
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        sum += max(fwd[i], bwd[i]);
    }
    cout<<sum<<endl;

    delete [] arr;
    delete [] fwd;
    delete [] bwd;
    return 0;
}