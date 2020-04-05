#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin>>n;
    string s;
    while(n--){
        cin>>s;
        ll len = s.length();
        ll ** cdf = new ll*[26];
        for (ll i = 0; i < 26; i++)
        {
            cdf[i] = new ll[len];
        }

        for (ll j = 0; j < 26; j++)
        {
            if(j == s[0]-97){
                cdf[j][0] = 1;
            } else {
                cdf[j][0] = 0;
            }
        }
        for (ll i = 1; i < len; i++)
        {
            for (ll j = 0; j < 26; j++)
            {
                if(j == s[i]-97){
                    cdf[j][i] = cdf[j][i-1]+1;
                } else {
                    cdf[j][i] = cdf[j][i-1];
                }
            }
        }

        ll count = 0;
        for (ll i = 0; i < len; i++)
        {
            for (ll j = i; j < len; j++)
            {
                ll sub_len = j-i;
                for (ll k = 0; k+sub_len < len; k++)
                {
                    if(i == k){
                        continue;
                    }
                    bool flag = true;
                    for (ll letter = 0; letter < 26; letter++)
                    {
                        ll a, b;
                        if(k == 0){
                            a = (cdf[letter][k+sub_len]);
                        } else {
                            a = (cdf[letter][k+sub_len]-cdf[letter][k-1]);
                        }
                        if(i == 0){
                            b = (cdf[letter][j]);
                        } else {
                            b = (cdf[letter][j]-cdf[letter][i-1]);
                        }
                        if(a != b){
                            flag = false;
                            break;
                        }
                    }
                    if(flag){
                        count++;
                    }
                }
                
            }
        }
        cout<<count/2<<endl;

        for (ll i = 0; i < 26; i++)
        {
            delete [] cdf[i];
        }
        delete [] cdf;
    }
    return 0;
}