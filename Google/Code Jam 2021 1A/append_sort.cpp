#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

void inc_str(string & s){
    ll i;
    for(i = s.length()-1; i>=0; i--){
        if(s[i] != '9'){
            s[i]++;
            break;
        }
    }
    i++;
    for(; i<s.length(); i++){
        s[i] = '0';
    }
}

ll helper(vector<string> & v, ll a, ll b){
    ll la = v[a].length(), lb = v[b].length(); 
    if(la<lb){
        return 0;
    } else if(la == lb){
        if(v[a] < v[b]){
            return 0;
        } else {
            v[b].push_back('0');
            return 1;
        }
    } else {
        // cout<<"hi1"<<endl;
        if(v[a] < v[b]){
            // cout<<"hi3"<<endl;
            v[b] += string(la-lb, '0');
            return la-lb;
        } else {
            // cout<<"hi2"<<endl;
            string sub = v[a].substr(0, lb);
            if(sub > v[b]){
                v[b] += string(la-lb+1, '0');
                return la-lb+1;
            } else {
                string suffix = v[a].substr(lb);
                if(suffix != string(la-lb, '9')){
                    inc_str(suffix);
                    v[b] += suffix;
                    return la-lb;
                } else {
                    v[b] += string(la-lb+1, '0');
                    return la-lb+1;
                }
            }
        }
    }
}

void solve(ll t){

    ll n;
    cin>>n;
    vector<string> v(n);
    for(auto & i:v){
        cin>>i;
    }
    ll res = 0;
    for(ll i = 1; i<n; i++){
        res += helper(v, i-1, i);
    }
    cout<<"Case #"<<t+1<<": "<<res<<endl;
    // for(auto i:v){
    //     cout<<i<<" ";
    // } cout<<endl;

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