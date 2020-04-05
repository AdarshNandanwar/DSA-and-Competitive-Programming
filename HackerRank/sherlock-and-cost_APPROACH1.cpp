#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll * solve(ll * b, ll n){
    ll * a = new ll[n];
    for (ll i = 0; i < n; i++)
    {
        a[i] = -1;
    }
    
    ll len = 1;

    for (ll i = 1; i < n; i++)
    {
        if(b[i] >= b[i-1]){
            len++;
        }
        if(b[i] < b[i-1] || i==n-1){
            if(len >= 2){
                if(i == n-1) i++;
                int toggle = 1;
                for (ll j = 1; j <= len; j++)
                {
                    if(toggle){
                        a[i-j] = b[i-j];
                    } else {
                        a[i-j] = 1;
                    }
                    toggle ^= 1;
                }
            }
            len = 1;
        }
    }

    // for (ll i = 0; i < n; i++)
    // {
    //     cout<<a[i]<<" ";
    // }cout<<endl;

    len = 1;
    for (ll i = n-2; i >= 0; i--)
    {
        if(b[i] > b[i+1]){
            len++;
        }
        if(b[i] <= b[i+1] || i==0){
            if(len >= 2){
                if(i == 0) i--;
                int toggle = 1;
                for (ll j = 1; j <= len; j++)
                {
                    if(toggle){
                        a[i+j] = b[i+j];
                    } else {
                        a[i+j] = 1;
                    }
                    toggle ^= 1;
                }
            }
            len = 1;
        }
    }

    return a;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll * b = new ll[n];
        for (ll i = 0; i < n; i++)
        {
            cin>>b[i];
        }
        ll * a = solve(b, n);

        // for (ll i = 0; i < n; i++)
        // {
        //     cout<<a[i]<<" ";
        // }cout<<endl;

        ll ans = 0;
        for (ll i = 1; i < n; i++)
        {
            ans += abs(a[i]-a[i-1]);
        }
        cout<<ans<<endl;
        
        delete [] b;
    }
    return 0;
}