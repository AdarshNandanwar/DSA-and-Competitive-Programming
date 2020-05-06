#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;

void multiply(vector<ll> & res, ll n){
    ll temp, carry = 0, digit;
    for (ll i = 0; i < res.size(); i++)
    {
        temp = res[i]*n+carry;
        digit = temp%10;
        carry = temp/10;
        res[i] = digit;
    }
    for (ll i = carry; i > 0; i/=10)
    {
        res.push_back(i%10);
    }
}

void solve(){
    vector<ll> res;
    for (ll i = n; i > 0; i/=10)
    {
        res.push_back(i%10);
    }
    
    for (ll i = n-1; i > 0; i--)
    {
        multiply(res, i);
    }
    
    for (ll i = res.size()-1; i >= 0; i--)
    {
        cout<<res[i];
    }cout<<endl;
}
 
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    solve();
    return 0;
}