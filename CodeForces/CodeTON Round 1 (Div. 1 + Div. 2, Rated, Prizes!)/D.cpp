#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

void solve(){
    ll n;
    cin>>n;
    for(int k = 2; n>=(k*(k-1))/2; k++){
        if((n-(k*(k-1))/2)%k==0){
            cout<<k<<endl;
            return;
        }
    }
    cout<<-1<<endl;
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