#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll * A = new ll[n];
        ll * B = new ll[n];
        for (ll i = 0; i < n; i++)
        {
            cin>>A[i];
        }
        for (ll i = 0; i < n; i++)
        {
            cin>>B[i];
        }
        sort(A, A+n);
        sort(B, B+n);
        ll ans = 0;
        for (ll i = 0; i < n; i++)
        {
            ans += min(A[i], B[i]);
        }
        cout<<ans<<endl;
        delete [] A;
        delete [] B;
    }
}