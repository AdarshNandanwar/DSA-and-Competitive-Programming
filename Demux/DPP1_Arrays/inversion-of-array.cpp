#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll merge(vector<ll> & v, ll st, ll mid, ll end){
    int i = st, j = mid+1, inv = 0;
    vector<ll> temp;
    
    while(i<=mid and j<=end){
        if(v[i] <= v[j]){
            temp.push_back(v[i]);
            i++;
        } else {
            temp.push_back(v[j]);
            inv += (mid-i+1);
            j++;
        }
    }
    while(i<=mid){
        temp.push_back(v[i]);
        i++;
    }
    while(j<=end){
        temp.push_back(v[j]);
        j++;
    }
    int index = 0;
    for(int i = st; i<=end; i++){
        v[i] = temp[index++];
    }
    return inv;
}

ll countInversions(vector<ll> & v, ll st, ll end){
    
    if(st>=end) return 0;
    
    ll mid = st+(end-st)/2;
    ll left = countInversions(v, st, mid);
    ll right = countInversions(v, mid+1, end);
    ll res = left+right;
    
    res += merge(v, st, mid, end);
    
    return res;
}




ll n;

void solve(){

    cin>>n;
    vector<ll> v(n);
    for(auto & i:v){
        cin>>i;
    }

    cout<<countInversions(v, 0, n-1)<<endl;

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