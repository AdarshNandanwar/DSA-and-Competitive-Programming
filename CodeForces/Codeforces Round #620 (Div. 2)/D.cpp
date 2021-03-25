#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;

void solve(){

    cin>>n;
    string s;
    cin>>s;
    ll * arr1 = new ll[n+1];
    ll curr = 1, skipped = 1;
    for (ll i = 0; i < n; i++)
    {
        if(i == n-1 || s[i] == '<'){
            for (ll j = 1; j <= skipped; j++)
            {
                arr1[i+1-j] = curr;
                curr++;
            }
            skipped = 1;
        } else{
            skipped++;
        }
    }


    ll * arr2 = new ll[n+1];
    curr = 1; skipped = 1;
    for (ll i = n-2; i >= -1; i--)
    {
        if(i == -1 || s[i] == '>'){
            for (ll j = 1; j <= skipped; j++)
            {
                arr2[i+j] = curr;
                curr++;
            }
            skipped = 1;
        } else{
            skipped++;
        }
    }
    for (ll i = 0; i < n; i++)
    {
        cout<<arr2[i]<<" ";
    }cout<<endl;
    for (ll i = 0; i < n; i++)
    {
        cout<<arr1[i]<<" ";
    }cout<<endl;
    

}
 
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}