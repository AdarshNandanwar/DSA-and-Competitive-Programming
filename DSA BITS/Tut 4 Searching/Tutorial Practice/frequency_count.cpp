#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, k;
    cin>>n>>k;
    vector<ll> v;
    for (ll i = 0; i < n; i++)
    {
        ll temp;
        cin>>temp;
        v.push_back(temp);
    }
    // cout<<"found: "<<*upper_bound(v.begin(), v.end(), k)<<" "<<*lower_bound(v.begin(), v.end(), k)<<endl;
    // cout<<"not found: "<<*upper_bound(v.begin(), v.end(), 2)<<" "<<*lower_bound(v.begin(), v.end(), 2)<<endl;
    cout<<upper_bound(v.begin(), v.end(), k)-lower_bound(v.begin(), v.end(), k)<<endl;
    
    return 0;
}