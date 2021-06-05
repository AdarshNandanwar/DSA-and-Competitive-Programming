#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;


void swap(ll & a, ll & b){
    ll temp = a;
    a = b;
    b = temp;
}


void solve(ll t_id){

    ll n, k;
    cin>>n>>k;
    vector<ll> v(n);
    for(auto & i:v) cin>>i;
    sort(v.begin(), v.end());
    vector<ll> winnable;
    ll max_ele = INT_MIN;
    for(ll i = 0; i<n; i++){
        if(i == 0){
            winnable.push_back(v[i]-1);
        } else {
            winnable.push_back((v[i]-v[i-1])/2);
            max_ele = max(max_ele, v[i]-v[i-1]-1);
        }
        if(i == n-1){
            winnable.push_back(k-v[i]);
        }
    }
    ll a1 = INT_MIN, a2 = INT_MIN;
    for(ll i:winnable){
        if(i>a1){
            a2 = a1;
            a1 = i;
        } else if(i>a2){
            a2 = i;
        }
    }
    max_ele = max(max_ele, a1+a2);
    double ans = ((double)max_ele)/k;

    printf("Case #%lld: %.8lf\n", t_id+1, ans);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    for(ll i = 0; i<t; i++){
        solve(i);
    }

    return 0;
}