#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll h, m, eta = 0;
        cin>>h>>m;
        if(h == 0){
            eta += (23*60);
        } else {
            eta += ((23-h)*60);
        }
        eta += (60-m);
        cout<<eta<<endl;
    }
    return 0;
}