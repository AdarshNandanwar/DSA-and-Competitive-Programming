#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
    
vector<ll> v;
ll n, k;

bool can_do(ll x){
    ll ops = 0;
    for (ll i = n/2; i < n; i++)
    {
        if(v[i] >= x){
            break;
        } else {
            ops += (x-v[i]);
            if(ops > k){
                return false;
            }
        }
    }
    return true;
}

ll binary_search_median(){
    ll low = 0, high = 2e9, mid;
    while(low<high){
        // mid = low + (high-low)/2;
        mid = low + (high-low+1)/2;
        // cout<<low<<" "<<high<<" "<<mid<<endl;
        if(can_do(mid)){
            low = mid;
        } else {
            high = mid-1;
        }
    }
    return low;
}

int main(){
    cin>>n>>k;
    for (ll i = 0; i < n; i++)
    {
        ll temp;
        cin>>temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    
    ll ans = binary_search_median();
    // ll ans = can_do(1000);
    cout<<ans<<endl;
    return 0;
}