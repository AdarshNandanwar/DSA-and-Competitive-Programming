#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

void solve(){


    cin>>n;
    ll first_min, first_max, last_min, last_max, min_ind = 0, max_ind = n-1;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin>>v[i];

        if(v[min_ind] > v[i]) first_min = last_min = min_ind = i;
        else if(v[min_ind] == v[i]) last_min = i;

        if(v[max_ind] < v[i]) first_max = last_max = max_ind = i;
        else if(v[max_ind] == v[i]) last_max = i;
    }
    
    ll res1 = abs(v[last_max]-v[first_min])+abs(last_max-first_min);
    ll res2 = abs(v[last_max]-v[first_min])+abs(last_min-first_max);
    ll res3 = abs(v[n-1]-v[0])+n-1;

    cout<<max(res3, max(res1, res2))<<endl;
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