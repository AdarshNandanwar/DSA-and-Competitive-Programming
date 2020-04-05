#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, m;
        cin>>n>>m;
        map<ll, ll> freq;
        for (ll i = 0; i < m; i++)
        {
            ll temp;
            cin>>temp;
            for (ll i = 0; i <= 63; i++)
            {
                if(((ll)1<<i) == temp){
                    freq[i]++;
                }
            }
        }
        
        for (ll i = 63; i >= 0; i--)
        {
            if((ll)1<<i){
                bool ck1 = true, ck2 = true;
                for (ll j = 63; j >= i; j--)
                {
                    if(freq[j]){
                        freq[j-1]+=(2*freq[j]);
                        freq[j] = 0;
                    }
                    if(j == i){
                        if(freq[j] > 0){
                            freq[j] --;
                            ck1 = false;
                        }
                    }
                }
                for (ll j = 0; j <= i; j++)
                {
                    if(j == i){
                        if(freq[j] > 0){
                            freq[j] --;
                            ck1 = false;
                        }
                    }
                    if(freq[j]){
                        freq[j+1]+=(freq[j]/2);
                        freq[j] /= 2;
                    }
                }
                if(ck1 && ck2){
                    flag = false;
                    break;
                }
            }
        }
        


    }
    return 0;
}