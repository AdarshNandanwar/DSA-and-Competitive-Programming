#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;

        ll * arr = new ll[n];
        bool flag = true;

        for (ll i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        ll sum = 0;
        for (ll i = 0; i < n; i++)
        {
            sum += arr[i];
            if(sum <= 0){
                flag = false;
                break;
            }
        }
        sum = 0;
        for (ll i = n-1; i >= 0; i--)
        {
            sum += arr[i];
            if(sum <= 0){
                flag = false;
                break;
            }
        }
        
        if(flag){
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
        

        delete [] arr;
    }

    return 0;
}