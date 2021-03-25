#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long int ll;

ll n;

void solve(){

    scanf("%lld", &n);
    ll * arr = new ll[n];
    for (ll i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    ll * left_even = new ll[n];
    ll * right_even = new ll[n];
    left_even[0] = -1;
    for (ll i = 1; i < n; i++)
    {
        if(arr[i-1]%2 == 0){
            left_even[i] = i-1;
        } else {
            left_even[i] = left_even[i-1];
        }
    }
    right_even[n-1] = n;
    for (ll i = n-2; i >= 0; i--)
    {
        if(arr[i+1]%2 == 0){
            right_even[i] = i+1;
        } else {
            right_even[i] = right_even[i+1];
        }
    }
    
    ll ans = ((n*(n+1))/2);
    for (ll i = 0; i < n; i++)
    {
        if(arr[i]%4 == 2){
            ll left = i-left_even[i];
            ll right = right_even[i]-i;
            cout<<i<<": "<<left<<" "<<right<<endl;
            ans -= left*right;
        }
    }

    printf("%lld\n", ans);
}
 
int main(){

    ll t;
    scanf("%lld", &t);
    while(t--){
        solve();
    }
    return 0;
}