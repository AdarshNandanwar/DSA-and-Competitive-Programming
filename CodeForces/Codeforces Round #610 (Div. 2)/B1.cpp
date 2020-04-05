#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, p, k;
        cin>>n>>p>>k;
        ll * arr = new ll[n];

        for (ll i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        sort(arr, arr+n);
        ll c1 = 0, c2 = 0, count1 = 0, count2 = 0;
        ll index1 = 1, index2 = 2;
        if(arr[0]>p){
            cout<<0<<endl;
            continue;
        }
        c2+=arr[0];
        count2++;
        while(index1 < n && c1+arr[index1]<=p){
            c1+=arr[index1];
            index1+=2;
            count1+=2;
        }
        while(index2 < n && c2+arr[index2]<=p){
            c2+=arr[index2];
            index2+=2;
            count2+=2;
        }
        if(count1>count2){
            cout<<count1<<endl;
        } else {
            cout<<count2<<endl;
        }
        // cout<<count1<<" "<<count2<<endl;

        delete [] arr;
    }
    return 0;
}