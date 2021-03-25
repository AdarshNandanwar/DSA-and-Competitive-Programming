#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string converter(ll num, ll den){
    string ans = "";
    if(num*den >= 0){
        ans += "-";
    } else {
        ans += "+";
    }
    ll gcd_frac = __gcd(num, den);
    num /= gcd_frac;
    den /= gcd_frac;
    ans += num;
    ans += den;
    return ans;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;
    ll a[n], b[n];
    unordered_map<string, ll> m;
    for (ll i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (ll i = 0; i < n; i++)
    {
        cin>>b[i];
    }
    string max_d = "";
    ll max_count = 0, zeros = 0;
    for (ll i = 0; i < n; i++)
    {
        if(a[i]==0) {
            if(b[i] == 0){
                zeros++;
                continue;
            }
            continue;
        }
        m[converter(b[i], a[i])]++;
        if(m[converter(b[i], a[i])]>max_count){
            max_count = m[converter(b[i], a[i])];
            max_d = converter(b[i], a[i]);
        }
    }
    cout<<max_count+zeros<<endl;
    
    return 0;
}