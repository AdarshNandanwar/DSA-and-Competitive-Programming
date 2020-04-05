#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, d;
        cin>>n>>d;
        if(n >= d){
            cout<<"YES\n";
        } else {
            ll min_days = INT_MAX;
            for (ll i = 0; i < n; i++)
            {
                ll time = 0;
                time += i;
                if(d%(i+1) == 0){
                    time += d/(i+1);
                } else {
                    time += (d/(i+1)+1);
                }
                min_days = min(min_days, time);
            }
            if(min_days <= n){
                cout<<"YES\n";
            } else {
                cout<<"NO\n";
            }
        }
    }
    
    return 0;
}