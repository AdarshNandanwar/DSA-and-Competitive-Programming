#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll twoCount = 0, zeroCount = 0;;
        ll n;
        cin>>n;
        ll a;
        while(n--){
            cin>>a;
            if(a==0){
                zeroCount++;
            } else if (a==2){
                twoCount++;
            }
        }
        cout<<((zeroCount*(zeroCount-1))/2)+((twoCount*(twoCount-1))/2);
    }
    return 0;
}