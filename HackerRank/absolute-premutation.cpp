#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void swap(ll & a, ll & b){
    ll temp = a;
    a = b;
    b = temp;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, k;
        cin>>n>>k;
        if(k == 0){
            for (ll i = 0; i < n; i++)
            {
                cout<<i+1<<' ';
            }
            cout<<endl;
            continue;
        }
        if(n/2 < k || n%(2*k)){
            cout<<-1<<endl;
            continue;
        }
        ll * arr = new ll[n];
        for (ll i = 0; i < n; i++)
        {
            arr[i] = i+1;
        }
        ll no_of_groups = n/(2*k);
        for (ll i = 0; i < no_of_groups; i++)
        {
            for (ll j = i*(2*k); j < i*(2*k)+k; j++)
            {
                swap(arr[j], arr[j+k]);
            }
        }
        for (ll i = 0; i < n; i++)
        {
            cout<<arr[i]<<' ';
        }
        cout<<endl;
        delete [] arr;
    }
    return 0;
}