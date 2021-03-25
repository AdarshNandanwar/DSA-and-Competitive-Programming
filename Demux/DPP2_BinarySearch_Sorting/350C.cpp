#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

void solve(){

    ll count = 0;
    cin>>n;
    vector<pair<ll,ll>> v(n);
    for(auto & [a, b]:v){
        cin>>a>>b;
        count += (2+2*(bool)a+2*(bool)b);
    }

    sort(v.begin(), v.end(), [](const pair<ll,ll> & a, const pair<ll,ll> & b){return abs(a.first)+abs(a.second) < abs(b.first)+abs(b.second);});

    cout<<count<<endl;
    for(auto [a, b]:v){
        if(a>0) cout<<"1 "<<a<<" R\n";
        else if(a<0) cout<<"1 "<<-a<<" L\n";
        if(b>0) cout<<"1 "<<b<<" U\n";
        else if(b<0) cout<<"1 "<<-b<<" D\n";
        cout<<"2\n";
        if(a>0) cout<<"1 "<<a<<" L\n";
        else if(a<0) cout<<"1 "<<-a<<" R\n";
        if(b>0) cout<<"1 "<<b<<" D\n";
        else if(b<0) cout<<"1 "<<-b<<" U\n";
        cout<<"3\n";
    }

}
 
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 1;
    while(t--){
        solve();
    }
    return 0;
}