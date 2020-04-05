#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll a, b ;
        cin>>a>>b;
        ll B = b, digits = 0;
        while(B){
            digits++;
            B /= 10;
        }

        if(b == (pow(10, digits)-1)){
            cout<<a*digits<<endl;
        } else {
            cout<<a*(digits-1)<<endl;
        }
    }
    
    return 0;
}