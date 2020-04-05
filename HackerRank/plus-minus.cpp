#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin>>n;
    ll N = n;
    double a = 0, b = 0, c = 0;
    ll temp;
    while(N--){
        cin>>temp;
        if(temp>0){
            a++;
        } else if(temp<0){
            b++;
        } else {
            c++;
        }
    }
    a/=n;
    b/=n;
    c/=n;
    cout<<a<<endl<<b<<endl<<c<<endl;
    return 0;
}