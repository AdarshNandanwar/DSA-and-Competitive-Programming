#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string str;
    ll k, count = 0, ans = 0, mod_count = 0;
    cin>>str>>k;
    for (ll i = 0; i < str.length(); i++)
    {
        if(str[i] == 'a') count++;
    }

    if(k <= str.length()){
                
        for (ll i = 0; i < k; i++)
        {
            if(str[i] == 'a') mod_count++;
        }
        ans = mod_count;

    } else {
        ll repeat = k/str.length();
        ans += (repeat * count);
        for (ll i = 0; i < k%str.length(); i++)
        {
            if(str[i] == 'a') mod_count++;
        }
        ans += mod_count;
    }
    cout<<ans<<endl;
    return 0;
}