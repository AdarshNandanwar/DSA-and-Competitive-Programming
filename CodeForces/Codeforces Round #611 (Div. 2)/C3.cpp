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
    queue<ll> q;
    for (ll i = 0; i < n; i++)
    {
        if(!rec[i]){
            q.push(i+1);
        }
    }    

    for (ll i = 0; i < n; i++)
    {
        if(!arr[i]){
            ll temp  =q.front();
            if((i+1) == temp){
                q.pop();
                q.push(temp);
            }
            temp = q.front();
            arr[i] = temp;
            q.pop();
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