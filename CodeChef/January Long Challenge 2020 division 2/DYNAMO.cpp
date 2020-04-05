#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, s, a, b, c, d, e, verdict, power;
        cin>>n;
        power = pow(10, n);
        cin>>a;
        s = 2*(power) + a;
        cout<<s<<endl;
        cin>>b;
        c = power - b;
        cout<<c<<endl;
        cin>>d;
        e = power - d;
        cout<<e<<endl;
        cin>>verdict;
        if(verdict == -1){
            return 0;
        }
    }
    return 0;
}