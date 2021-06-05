#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

set<ll> st;

void compute(){
    for(ll i = 1; i<=10000; i++){
        ll cur = i;
        string s = to_string(i);
        for(ll j = i+1; cur <= 10000000; j++){
            s += to_string(j);
            cur = stoll(s);
            if(cur <= 10000000) st.insert(cur);
        }
    }
}

// void compute(){

//     queue<vector<ll>> q;

//     for(ll i = 1; i<=1000; i++){
//         q.push({i, i});
//     }

//     string str;

//     while(!q.empty()){
//         auto cur = q.front();
//         q.pop();
//         str = to_string(cur[0])+to_string(cur[1]+1);
//         if(stoll(str) <= 10000000){
//             q.push({stoll(str), cur[1]+1});
//             st.insert(stoll(str));
//         }
//         str = to_string(cur[0])+to_string(cur[0]+1);
//         if(stoll(str) <= 10000000){
//             q.push({stoll(str), cur[0]+1});
//             st.insert(stoll(str));
//         }
//     }
    
// }

void solve(ll t_id){

    ll y;
    cin>>y;
    
    auto itr = st.upper_bound(y);

    cout<<"Case #"<<t_id+1<<": "<<*itr<<endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    compute();

    ll t;
    cin>>t;
    for(ll i = 0; i<t; i++){
        solve(i);
    }

    return 0;
}