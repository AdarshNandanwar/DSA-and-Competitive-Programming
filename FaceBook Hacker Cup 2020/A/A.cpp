#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

void solve(){

    cin>>n;
    string I, O;
    cin>>I;
    cin>>O;
    vector<vector<ll>> adjList(n);
    for(ll i = 0; i<n; i++){
        for(ll j = max(0ll, i-1); j<=min(n-1, i+1); j++){
            if(O[i] == 'Y' and I[j] == 'Y') adjList[i].push_back(j);
        }
    }

    // dfs

    for(ll i = 0; i<n; i++){
        stack<ll> st;
        vector<bool> visited(n, 0);
        st.push(i);
        visited[i] = 1;
        while(!st.empty()){
            ll cur = st.top();
            st.pop();
            for(auto nbr:adjList[cur]){
                if(!visited[nbr]){
                    visited[nbr] = 1;
                    st.push(nbr);
                }
            }
        }
        for(auto v:visited) cout<<(v?'Y':'N');
        cout<<endl;
    }
}
 
int main(){
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    for(ll i = 1; i<=t; i++){
        cout<<"Case #"<<i<<":"<<endl;
        solve();
    }
    return 0;
}