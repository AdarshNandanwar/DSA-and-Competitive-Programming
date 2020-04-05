#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, s, k, dist = 0;
        cin>>n>>s>>k;
        map<ll, bool> m;
        for (ll i = 1; i < k+1; i++)
        {
            ll temp;
            cin>>temp;
            m[temp] = true;
        }
        while(m[s+dist] && m[s-dist]){
            dist++;
            if(s-dist < 1){
                while(m[s+dist]){
                    dist++;
                }
                break;
            } else if (s+dist > n){
                while(m[s-dist]){
                    dist++;
                }
                break;
            }
        }

        cout<<dist<<endl;
        
    }

    

    return 0;
}