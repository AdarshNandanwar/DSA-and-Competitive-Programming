#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin>>n;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n-i-1; j++)
        {
            cout<<" ";
        }
        for (ll j = 0; j < i+1; j++)
        {
            cout<<"#";
        }
        cout<<endl;
    }
    
    return 0;
}