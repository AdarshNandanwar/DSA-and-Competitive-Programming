#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> v(n);
        for (ll i = 0; i < n; i++)
        {
            cin>>v[i];
        }
        
        ll sum_so_far = 0, max_so_far = INT_MIN;
        bool all_neg = true;
        for (ll i = 0; i < n; i++)
        {
            sum_so_far += v[i];
            max_so_far = max(max_so_far, sum_so_far);
            if(sum_so_far < 0){
                sum_so_far = 0;
            }
            if(v[i] >= 0){
                all_neg = false;
            }
        }
        cout<<max_so_far<<" ";

        ll sum = 0;
        if(all_neg){
            cout<<*max_element(v.begin(), v.end())<<endl;
        } else {
            for (ll i = 0; i < n; i++)
            {
                if(v[i] >=0){
                    sum += v[i];
                }
            }
            
            cout<<sum<<endl;
        }
    }
    return 0;
}