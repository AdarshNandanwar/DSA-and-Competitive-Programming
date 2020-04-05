#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll n, min_fuel = INT_MAX, fuel = 0, index = 0, min_index;
    cin>>n;
    ll N = n;
    while(N--){
        ll a,d;
        cin>>a>>d;
        fuel+=(a-d);
        if(fuel < min_fuel){
            min_fuel = fuel;
            min_index = index;
        }
        index++;
    }
    ll ans = min_index+1;
    if(ans != n){
        cout<<ans<<endl;
    } else {
        cout<<0<<endl;
    }
    return 0;
}