#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, k;
        cin>>n>>k;
        ll * arr = new ll[n];
        ll * right = new ll[n];
        ll * left = new ll[n];
        ll * diff = new ll[n];
        for (ll i = 0; i < n; i++)
        {
            cin>>arr[i];
        }

        
        right[0] = (arr[0]%k);
        if(arr[n-1] % k == 0){
            left[n-1] = 0;
        } else {
            left[n-1] = k-(arr[n-1]%k);
        }
        for (ll i = 1; i < n; i++)
        {
            right[i] = right[i-1] + (arr[i]%k);
        }
        for (ll i = n-2; i >= 0; i--)
        {
            if(arr[i] % k == 0){
                left[i] = left[i+1];
            } else {
                left[i] = left[i+1]+k-(arr[i]%k);
            }
        }

        if(right[n-1] == 0){
            cout<<0<<endl;
            continue;
        }

        diff[n-1] = right[n-1];
        for (ll i = 0; i < n-1; i++)
        {
            diff[i] = right[i] - left[i+1];
        }
        
        // for (ll i = 0; i < n; i++)
        // {
        //     cout<<right[i]<<" "<<left[i]<<" "<<diff[i]<<" \n";
        // }cout<<endl;
        

        ll s = INT_MAX;
        for (ll i = 0; i < n; i++)
        {
            if(diff[i]>=0 && s>(diff[i]%k)){
                s = diff[i]%k;
            }
        }
        
        cout<<s<<endl;

        delete [] arr;
        delete [] right;
        delete [] left;
        delete [] diff;
    }
}