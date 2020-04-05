#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, p, i;
        cin>>n>>p;
        ll * arr = new ll[n];
        ll * den = new ll[n];
        for (i = 0; i < n; i++)
        {
            cin>>arr[i];
            den[i] = arr[i];
        }
        bool flag = false;
        for (i = 0; i < n; i++)
        {
            if(p%arr[i]){
                flag = true;
                break;
            }
        }
        if(flag){
            cout<<"YES ";

            for (ll j = 0; j < i; j++)
            {
                cout<<"0 ";
            }
            cout<<(p/arr[i])+1<<" ";
            for (ll j = i+1; j < n; j++)
            {
                cout<<"0 ";
            }          

            cout<<endl;
            continue;
        }
        ll var1, var2;
        sort(den, den+n);
        for (ll i = n-2; i >= 0; i--)
        {
            if(den[i+1]%den[i]){
                var1 = den[i];
                var2 = den[i+1];
                flag = true;
                break;
            }
        }
        if(flag){
            cout<<"YES ";

            for (ll i = 0; i < n; i++)
            {
                if(arr[i] == var1){
                    cout<<((p/var1)-1)<<" ";
                } else if(arr[i] == var2){
                    cout<<1<<" ";
                } else {
                    cout<<"0 ";
                }
            }
            
            cout<<endl;
            continue;
        }
        
        cout<<"NO"<<endl;

        delete [] arr;
    }
}