#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, N, k;
    cin>>N>>k;

    n = 100000;
    ll * arr = new ll[n]();
    
    for (ll i = 0; i < N; i++)
    {
        ll temp;
        cin>>temp;
        arr[temp-1] = 1;    
    }


    ll p = 0, count = 0;
    while(p!=n){
        if(!arr[p]){
            p++;
        }else{
            p = min(n-1, p+k);
            while(arr[p]==0){
                p--;
            }
            count++;
            p = min(n, p+k+1);
        }
    }
    cout<<count<<endl;

    delete [] arr;
    return 0;
}