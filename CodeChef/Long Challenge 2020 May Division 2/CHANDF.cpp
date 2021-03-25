#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

void printBinary(unsigned n) 
{
    if (n > 1) 
        printBinary(n/2);
    cout << n % 2; 
} 

ll n;

void solve(){

    ll x, y, l, r;
    cin>>x>>y>>l>>r;
    
    cout<<"x: ";
    printBinary(x);
    cout<<endl;
    cout<<"y: ";
    printBinary(y);
    cout<<endl;
    cout<<"(x|y): ";
    printBinary((x|y));
    cout<<endl;
    cout<<"r: ";
    printBinary(r);
    cout<<endl;

    if(x==0 || y==0){
        cout<<0<<endl;
        return;
    }
    ll z = (r & (x|y));
    ll max_ans = (x&z)*(y&z), temp;
    for (ll i = log2(r); i >= 1; i--){
        if(r & ((ll)1<<i)){
            temp = r & (~((ll)1<<i)) | (((ll)1<<i)-1);
            temp &= (x|y);
            cout<<i<<": ";
            printBinary(temp);
            cout<<endl;
            ll temp_ans = (x&temp)*(y&temp);
            if(temp_ans >= max_ans){
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