#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin>>n;
    ll sum = 0;
    ll a;
    while(n--){
        cin>>a;
        sum+=a;
    }
    cout<<sum<<endl;
    return 0;
}