#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll w, h, r;
    cin>>w>>h>>r;
    vector<ll> X, Y;
    for (ll i = 0; i < r; i++)
    {
        ll t1, t2;
        cin>>t1>>t2;
        X.push_back(t1);
        Y.push_back(t2);
    }
    ll n = 1, m = 1;
    for (ll i = w/2; i >= 1; i--)
    {
        if(w%i == 0){
            n = i;
            break;
        }
    }
    for (ll i = h/2; i >= 1; i--)
    {
        if(h%i == 0){
            m = i;
            break;
        }
    }
    cout<<n<<" "<<m<<" "<<0<<endl;

    return 0;
}