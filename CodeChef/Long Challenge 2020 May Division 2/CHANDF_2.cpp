#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

// void printBinary(unsigned n) 
// {
//     if (n > 1) 
//         printBinary(n/2);
//     cout << n % 2; 
// } 

ll n;

void solve(){

    ll x, y, l, r, z, max_ans, temp;
    cin>>x>>y>>l>>r;

    if(x==0 || y==0){
        cout<<0<<endl;
        return;
    }

    z = (r & (x|y));
    if(l<=z) max_ans = (x&z)*(y&z);
    for (ll i = log2(r); i >= 1; i--){
        if(r & ((ll)1<<i)){
            temp = r & (~((ll)1<<i)) | (((ll)1<<i)-1);
            temp &= (x|y);
            ll temp_ans = (x&temp)*(y&temp);
            if(temp_ans >= max_ans && temp >= l){
                z = temp;
                max_ans = temp_ans;
            }
        }
    }

    z = (l | (x|y));
    if(z<=r) max_ans = (x&z)*(y&z);
    for (ll i = log2(r); i >= 1; i--){
        if(!(l & ((ll)1<<i))){
            temp = l | ((ll)1<<i) & (~(((ll)1<<i)-1));
            temp |= ((((ll)1<<i)-1) & (x|y));
            ll temp_ans = (x&temp)*(y&temp);
            if(temp_ans >= max_ans && temp <= r){
                z = temp;
                max_ans = temp_ans;
            }
        }
    }
    cout<<z<<endl;
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