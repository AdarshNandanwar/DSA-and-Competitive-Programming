#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll mergeArrays(vector<ll> & v, int st, int mid, int en){
    ll p1 = st, p2 = mid+1, count = 0;
    vector<ll> temp;
    while(p1<=mid || p2<=en){
        if(p1<=mid and p2<=en){
            if(v[p1]<=v[p2]) temp.push_back(v[p1++]);
            else {
                count += (mid-p1+1);
                temp.push_back(v[p2++]);
            }
        } else if(p1<=mid){
            temp.push_back(v[p1++]);
        } else{
            temp.push_back(v[p2++]);
        }
    }
    ll ind = 0;
    for(int i = st; i<=en; i++){
        v[i] = temp[ind++];
    }
    return count;
}

ll countInversion(vector<ll> & v, int st, int en){
    if(en-st<=0) return 0;
    ll mid = st+(en-st)/2;
    return countInversion(v, st, mid) + countInversion(v, mid+1, en) + mergeArrays(v, st, mid, en);
}

ll n;

void solve(){

    cin>>n;
    vector<ll> v(n);
    for(auto & i:v) cin>>i;
    cout<<countInversion(v, 0, n-1)<<endl;
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