#include <bits/stdc++.h>
using namespace std;
typedef long double ll;

ll n;

string to_string(ll m, ll c){
    string str = "";
    str += to_string(m);
    str += ":";
    str += to_string(c);
    return str;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    vector<pair<ll, ll>> v;
    for (ll i = 0; i < n; i++)
    {  
        ll x, y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    unordered_map<string, ll> lines;
    ll max_count = 0;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = i+1; j < n; j++)
        {
            ll m, c, x1, x2, y1, y2;
            x1 = v[i].first;
            x2 = v[j].first;
            y1 = v[i].second;
            y2 = v[j].second;
            m = (y2-y1)/(x2-x1);
            c = y2-(m*x2);
            lines[to_string(m, c)]++;
            // cout<<x1<<", "<<y1<<":"<<x2<<", "<<y2<<" m: "<<m<<" c: "<<c<<endl;
            // cout<<to_string(m, c)<<": "<<lines[to_string(m, c)]<<endl;
            max_count = max(max_count, lines[to_string(m, c)]);
        }
    }
    cout<<floor(sqrt(max_count*2))+1<<endl;
   
    return 0;
}