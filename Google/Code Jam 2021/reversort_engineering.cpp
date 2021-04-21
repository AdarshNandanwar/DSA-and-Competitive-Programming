#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    
    ll t, n, cost, len;
    cin>>t;
    for(int k = 1; k<=t; k++){
        cin>>n>>cost;

        if(cost < n-1 or ((n+2)*(n-1))/2 < cost){
            cout<<"Case #"<<k<<": IMPOSSIBLE"<<endl;
            continue;
        }

        vector<ll> res(n, 0);
        for(ll i = 1; i<=n; i++) res[i-1] = i;

        cost -= (n-1);
        ll left = 0, right = n;

        for(int i = 0; i<n and cost; i++){
            len = min(cost, right-left-1);
            reverse(res.begin()+left, res.begin()+left+len+1);
            if(i%2){
                left++;
            } else {
                right--;
            }
            cost -= len;
        }

        cout<<"Case #"<<k<<": ";
        for(auto i:res) cout<<i<<" "; cout<<endl;


        // check
        // cost = 0;
        // for(int i = 0; i<n-1; i++){
        //     auto min_ele = min_element(res.begin()+i, res.end());
        //     ll index = min_ele-res.begin();
        //     reverse(res.begin()+i, res.begin()+index+1);
        //     cost += (index-i+1);
        // }
        // cout<<"Case #"<<k<<": "<<cost<<endl;
    }
    
    return 0;
}