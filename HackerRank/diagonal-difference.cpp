#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin>>n;
    ll ** arr = new ll*[n];
    for (ll i = 0; i < n; i++)
    {
        arr[i] = new ll[n];
        for (ll j = 0; j < n; j++)
        {
            cin>>arr[i][j];
        }
        
    }
    
    ll sum1 = 0, sum2 = 0;
    for (ll i = 0; i < n; i++)
    {
        sum1+=arr[i][i];
    }
    for (ll i = 0; i < n; i++)
    {
        sum2+=arr[i][n-i-1];
    }
    cout<<abs(sum1-sum2)<<endl;
    for (ll i = 0; i < n; i++)
    {
        delete [] arr[i];
    }
    delete [] arr;
    return 0;
}