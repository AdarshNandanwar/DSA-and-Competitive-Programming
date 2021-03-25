#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

void solve(){

    cin>>n;
    string s;
    cin>>s;
    string res = "";
    for(int i =0; i<n; i++){
        if(s[i] <= '1'){
            continue;
        } else if(s[i] == '4'){
            res.push_back('3');
            res.push_back('2');
            res.push_back('2');
        } else if(s[i] == '6'){
            res.push_back('5');
            res.push_back('3');
        } else if(s[i] == '8'){
            res.push_back('7');
            res.push_back('2');
            res.push_back('2');
            res.push_back('2');
        } else if(s[i] == '9'){
            res.push_back('7');
            res.push_back('3');
            res.push_back('3');
            res.push_back('2');
        } else {
            res.push_back(s[i]);
        }
    }
    sort(res.begin(), res.end(), greater<char>());
    cout<<res<<endl;
}
 
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 1;
    while(t--){
        solve();
    }
    return 0;
}