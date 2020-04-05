#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll * solve(ll * arr, ll n){
    ll * rec = new ll[n]();
    for (ll i = 0; i < n; i++)
    {
        if(arr[i]){
            rec[arr[i]-1] = i+1;
        }
    }
    ll p1 = n-1;
    for (ll i = 0; i < n; i++)
    {
        if(!arr[i]){
            while(rec[p1] || p1 == i){
                if(p1){
                    p1--;
                } else {
                    p1 = n-1;
                }
            }
            rec[p1] = i+1;
            arr[i] = p1+1;
        }
    }
    
    return arr;

}

int main(){
    ll n;
    cin>>n;
    ll * arr = new ll[n];
    for (ll i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    arr = solve(arr, n);
    for (ll i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;
    
    return 0;
}