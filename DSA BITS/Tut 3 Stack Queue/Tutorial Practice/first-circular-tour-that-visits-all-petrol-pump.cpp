#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){

    ll n, fuel = 0, index = 0;
    cin>>n;
    pair<ll,ll> * arr = new pair<ll,ll>[n];
    queue<pair<ll,ll>> q;
    for (ll i = 0; i < n; i++)
    {
        ll p, d;
        cin>>p>>d;
        arr[i] = {p, d};
    }

    ll i = 0;
    while(true){
        if(q.size() == n && fuel >= 0) break;
        while(fuel < 0 && !q.empty()){
            pair<ll,ll> p = q.front();
            q.pop();
            fuel -= (p.first - p.second);
            index++;
        }
        fuel += (arr[i].first - arr[i].second);
        q.push(arr[i]);
        i = (i+1)%n;
    }

    cout<<(index)%n<<endl;
    
    return 0;
}