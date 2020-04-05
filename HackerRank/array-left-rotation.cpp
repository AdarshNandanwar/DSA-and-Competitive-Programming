#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void printRotate(ll * arr, ll n, ll d){
    for (ll i = 0; i < n; i++)
    {
        cout<<arr[(i+d)%n]<<" ";
    }
    cout<<endl;
}

int main(){
    ll n, d;
    cin>>n>>d;
    ll * arr = new ll[n];
    for (ll i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    printRotate(arr, n, d);

    delete [] arr;
    
    return 0;
}
