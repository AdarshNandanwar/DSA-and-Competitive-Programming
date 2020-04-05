#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, g, b;
        cin>>n>>g>>b;
        ll N =n;
        if(g>=b){
            cout<<n<<endl;
        } else {
            if(n%2){
                n /= 2;
                n++;
            } else {
                n /= 2;
            }
            if(n%g == 0){
                cout<<max((((n/g)-1)*(g+b))+g, N)<<endl;
            } else {
                cout<<max(((n/g)*(g+b))+(n%g), N)<<endl;
            }
        }
    }
    return 0;
}