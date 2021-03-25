#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin>>n;
    ll cap = 0, curr = 0;
    for (ll i = 0; i < n; i++)
    {
        ll exit, enter;
        cin>>exit>>enter;
        curr += (enter-exit);
        cap = max(cap, curr);
    }
    cout<<cap<<endl;
    return 0;
}