#include<bits/stdc++.h>
using namespace std;
typedef double ll;

int main(){
    ll n;
    cin>>n;
    ll sum = 0;
    for (ll i = 1; i <= n; i++)
    {
        sum += (((double)1)/i);
    }
    cout<<sum<<endl;
    return 0;
}