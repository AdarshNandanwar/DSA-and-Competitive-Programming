#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

void solve(){

    ll q;
    cin>>n>>q;
    string s;
    cin>>s;
    ll len = s.length();
    map<char, ll> m;
    for(int i = 0; i<len; i++){
        m[s[i]]++;
    }
    ll c, count;
    while(q--){
        cin>>c;
        count = 0;
        for(int i = 'a'; i<='z'; i++){
            if(m[i] > c){
                count += (m[i]-c);
            }
        }
        cout<<count<<endl;
    }
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