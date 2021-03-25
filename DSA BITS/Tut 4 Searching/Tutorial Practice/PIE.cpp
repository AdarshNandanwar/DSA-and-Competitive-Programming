#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, arr[10001], f;

bool isValid(double vol){
    bool ans = true;
    ll count = 0;
    for (ll i = 0; i < n; i++)
    {
       count += floor((M_PI*(double)arr[i]*(double)arr[i])/vol);
    }
    if(count < f){
        return false;
    } else {
        return true;
    }
}

void solve(){

    cin>>n>>f;
    ll max_r = 0;
    for (ll i = 0; i < n; i++)
    {
        cin>>arr[i];
        max_r = max(max_r, arr[i]);
    }
    f++;
    double low = (double)0, high = M_PI*(double)max_r*(double)max_r, mid;
    while((high-low)>=0.0001){
        mid = (low+high)/2;
        if(isValid(mid)){
            low = mid;
        } else {
            high = mid;
        }
    }
    printf("%.4f\n", mid);
    return;
}
 
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}