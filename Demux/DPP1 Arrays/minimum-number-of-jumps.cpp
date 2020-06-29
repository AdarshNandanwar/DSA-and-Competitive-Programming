#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

ll solve(){

    cin>>n;
    vector<ll> v(n);
    for(auto & i:v) cin>>i;

    if(n == 0 || n == 1) return 0;

    int pos = 0, count = 1, maxHop = INT_MIN, maxInd = 0;
    while(true){
        maxHop = INT_MIN;
        maxInd = -1;
        for(int i = 1; i<=v[pos]; i++){
            if(pos+i>=n-1) return count;
            if(v[pos+i]+i >= maxHop){
                maxHop = v[pos+i]+i;
                maxInd = pos+i;
            }
        }
        if(maxInd == -1) return -1;
        pos = maxInd;
        count++;
    }
    return count;
}
 
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
    return 0;
}