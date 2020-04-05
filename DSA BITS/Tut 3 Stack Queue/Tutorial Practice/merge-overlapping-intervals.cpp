#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<ll, ll>> mergeIntervals(vector<pair<ll, ll>> v, ll n){
    sort(v.begin(), v.end());
    stack<pair<ll,ll>> st;
    vector<pair<ll, ll>>::iterator itr;
    for(itr = v.begin(); itr != v.end(); itr++){
        if(!st.empty()){
            pair<ll, ll> p = st.top();
            if(p.second >= itr->first){
                st.pop();
                st.push({p.first, itr->second});
            } else {
                st.push(*itr);
            }
        } else {
            st.push(*itr);
        }
    }
    vector<pair<ll, ll>> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    ll n;
    cin>>n;
    vector<pair<ll, ll>> v;
    for (ll i = 0; i < n; i++)
    {
        ll a, b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    vector<pair<ll, ll>> ans = mergeIntervals(v, n);
    vector<pair<ll, ll>>::iterator itr;
    for(itr = ans.begin(); itr!=ans.end(); itr++){
        cout<<itr->first<<" "<<itr->second<<endl;
    }
    
    return 0;
}