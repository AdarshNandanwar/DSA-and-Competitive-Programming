#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, q;
    cin>>n>>q;
    vector<vector<ll>> arr(n);
    ll lastAns = 0;
    while(q--){
        ll type, x, y;
        cin>>type>>x>>y;
        ll index = ((x^lastAns)%n);
        if(type == 1){
            arr[index].push_back(y);
        } else {
            lastAns = arr[index][y%arr[index].size()];
            cout<<lastAns<<endl;
        }
    }

    return 0;
}