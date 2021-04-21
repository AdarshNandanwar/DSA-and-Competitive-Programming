#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    
    ll t, n;
    cin>>t;
    for(int k = 1; k<=t; k++){
        ll cost = 0;
        cin>>n;
        vector<ll> v(n);
        for(auto & i:v) cin>>i;
        
        for(int i = 0; i<n-1; i++){
            auto min_ele = min_element(v.begin()+i, v.end());
            ll index = min_ele-v.begin();
            reverse(v.begin()+i, v.begin()+index+1);
            cost += (index-i+1);
        }
        
        cout<<"Case #"<<k<<": "<<cost<<endl;
    }
    
    return 0;
}