#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, lcount = 0, rcount = 0;
    cin>>n;
    string s;
    cin>>s;
    for (ll i = 0; i < n; i++)
    {
        if(s[i] == 'L'){
            lcount++;
        } else {
            rcount++;
        }
    }
    cout<<lcount+rcount+1<<endl;
    
    return 0;
}