#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(vector<ll> v, ll pos){
    if(pos < 0){
        return 0;
    }
    
    vector<ll> one, zero;
    vector<ll>::iterator itr;


    for(itr = v.begin(); itr != v.end(); itr++){
        if(((*itr)&((ll)1<<pos))){
            one.push_back(*itr ^ ((ll)1<<pos));
        } else{
            zero.push_back(*itr);
        }
    }


    if(one.empty()){
        return solve(zero, pos-1);
    }
    if(zero.empty()){
        return solve(one, pos-1);
    }
    ll one_ans, zero_ans;
    one_ans = ((ll)1<<pos) + solve(one, pos-1);
    zero_ans = ((ll)1<<pos) + solve(zero, pos-1);
    
    return min(one_ans, zero_ans);
}

int main(){
    ll n;
    cin>>n;
    vector<ll> v;
    for (ll i = 0; i < n; i++)
    {
        ll temp;
        cin>>temp;
        v.push_back(temp);
    }

    ll X = solve(v, 30);
    cout<<X<<endl;

    return 0;
}