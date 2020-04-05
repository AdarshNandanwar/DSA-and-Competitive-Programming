#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

map<ll, ll> M;


ll solve(string a, string b, ll m){
    ll topics = 0;
    for (ll i = 0; i < m; i++)
    {
        if(a[i] == '1' || b[i] == '1') topics++;
    }
    M[topics]++;
    return topics;
}

int main(){
    ll n, m, max_topic = -1;
    cin>>n>>m;
    string * arr = new string[n];
    for (ll i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    for (ll i = 0; i < n; i++)
    {
        for (ll j = i+1; j < n; j++)
        {
            max_topic = max(max_topic, solve(arr[i], arr[j], m));
        }
        
    }
    
    cout<<max_topic<<endl<<M[max_topic]<<endl;

    delete [] arr;
    return 0;
}