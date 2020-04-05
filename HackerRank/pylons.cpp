#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, k;
    cin>>n>>k;
    ll * arr = new ll[n];

    for (ll i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    bool flag = false;
    ll dist = 1000000;
    ll * arr2 = new ll[n];
    for (ll i = 0; i < n; i++)
    {
        if(arr[i]){
            arr2[i] = 0;
            dist = 0;
            flag = true;
        } else {
            if(flag) dist++;
            arr2[i] = dist;
        }
    }
    dist = 1000000, flag = false;
    ll * arr3 = new ll[n];
    for (ll i = n-1; i >= 0; i--)
    {
        if(arr[i]){
            arr3[i] = 0;
            dist = 0;
            flag = true;
        } else {
            if(flag) dist++;
            arr3[i] = dist;
        }
    }
    for (ll i = 0; i < n; i++)
    {
        arr2[i] = min(arr2[i], arr3[i]);
        if(arr2[i] >= k){
            cout<<-1<<endl;
            return 0;
        }
    }
    

    ll p = 0, count = 0;
    while(p!=n){
        p = min(n-1, p+k-1);
        while(arr[p]==0){
            p--;
        }
        count++;
        p = min(n, p+k);
    }
    cout<<count<<endl;

    delete [] arr;
    return 0;
}