#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin>>n;
    while(n--){
        string s, ans = "";
        cin>>s;
        ll count = 1, len = s.length();
        for (ll i = 1; i < len; i++)
        {
            if(s[i] == s[i-1]){
                count++;
            } else {
                ans += to_string(count);
                ans += s[i-1];
                count = 1;
            }
        }
        ans += to_string(count);
        ans += s[len-1];

        cout<<ans<<endl;
    }
    return 0;
    
}