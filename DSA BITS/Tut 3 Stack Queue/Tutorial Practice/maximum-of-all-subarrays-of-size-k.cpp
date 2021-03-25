#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){

    ll n, k, d;
    cin>>n>>k;
    ll * arr = new ll[n];
    deque<ll> dq;
    cin>>arr[0];
    dq.push_back(0);
    for (ll i = 1; i < n; i++)
    {
        cin>>arr[i];
        while(!dq.empty() && arr[dq.back()] < arr[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        while(!dq.empty() && i-dq.front() >= k){
            dq.pop_front();
        }
        if(i>=k-1)cout<<arr[dq.front()]<<" ";
    }
    cout<<endl;
    return 0;
}