#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, k;
        cin>>n>>k;
        ll whole = n%k;
        ll ans = (n/k)*k;
        ans += min(whole, k/2);
        cout<<ans<<endl;
    }
    return 0;
}