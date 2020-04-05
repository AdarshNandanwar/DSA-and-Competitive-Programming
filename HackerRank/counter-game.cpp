#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll i = 0, ones = 0, zeros = 0, flag = 1;
        while (n)
        {
            if(n&1){
                flag = 0;
                ones++;
            }
            if(flag){
                zeros++;
            }
            n >>= 1;
        }
        
        ll turns = ones - 1 + zeros;
        if(turns&1){
            cout<<"Louise"<<endl;
        } else {
            cout<<"Richard"<<endl;
        }
    }
    return 0;
}