#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    // ll n;
    // cin>>n;
    // ll * arr = new ll[n];
    // for (ll i = 0; i < n; i++)
    // {
    //     cin>>arr[i];
    // }


    for (ll i = 0; i < 16; i++)
    {
        // for (ll j = 0; j < n; j++)
        // {
        //     cout<<(i^j)<<" ";
        // }
        // cout<<endl;
        cout<<(6^i)<<" "<<(9^i)<<" "<<(14^i)<<" "<<(12^i)<<" "<<endl;
    }
    

    return 0;
}