#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

struct Cycle{
    ll i1, i2, i3;
    Cycle(ll i1, ll i2, ll i3):i1(i1), i2(i2), i3(i3){};
};

ll n;

void solve(){
    ll k;
    cin>>n>>k;
    vector<ll> pos(n+1), v(n+1);
    vector<Cycle> cycles;
    ll count = 0, i1, i2, i3;
    for(int i = 1; i<=n; i++){
        cin>>v[i];
        pos[v[i]] = i;
    }
    for(int i = 1; i<=n; i++){
        // if(v[i] != i){
            if(count >= k){
                cout<<-1<<endl;
                return;
            }

            i1 = i;
            i2 = n-1;
            i3 = n-i+1;

            // i1 = pos[i];
            // i2 = pos[n-1];
            // i3 = pos[n-i+1];

            Cycle * trio = new Cycle(i1, i2, i3);
            cycles.push_back(*trio);
            ll temp = v[i3];
            v[i3] = v[i2];
            pos[v[i3]] = i3;
            v[i2] = v[i1];
            pos[v[i2]] = i2;
            v[i1] = temp;
            pos[v[i1]] = i1;
            count++;
        // }
    }
    cout<<count<<endl;
    for(auto i:cycles){
        cout<<i.i1<<" "<<i.i2<<" "<<i.i3<<endl;
    }
    for(ll i =1; i<=n; i++){
        cout<<v[i]<<" ";
    }cout<<endl;
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