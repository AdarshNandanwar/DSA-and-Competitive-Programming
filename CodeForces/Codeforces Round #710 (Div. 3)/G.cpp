#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

string helper(string & s, unordered_map<char, ll> & freq, unordered_set<string> & dp){
    dp.insert(s);
    if(s.length() == freq.size()){
        return s;
    }

    string res = "";
    
    for(int i = 0; i<s.length(); i++){
        if(freq[s[i]]<=1) continue;

        freq[s[i]]--;
        string next = s.substr(0, i)+s.substr(i+1);
        if(!dp.count(next)) res = max(res, helper(next, freq, dp));
        freq[s[i]]++;
    }

    return res;
}

void solve(){

    string s;
    cin>>s;

    unordered_set<string> dp;
    unordered_map<char, ll> freq;
    for(auto c:s) freq[c]++;

    cout<<helper(s, freq, dp)<<endl;
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