#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll * solve(ll * arr, ll n){
    ll * rec = new ll[n]();
    for (ll i = 0; i < n; i++)
    {
        if(arr[i]){
            rec[arr[i]-1] = i+1;
        }
    }
    vector<ll> notRec;
    for (ll i = 0; i < n; i++)
    {
        if(!rec[i]){
            notRec.push_back(i+1);
        }
    }
    sort(notRec.begin(), notRec.end(), greater<int>());
    // for (ll i = 0; i < notRec.size(); i++)
    // {
    //     cout<<notRec[i]<<" ";
    // }cout<<endl;
    

    for (ll i = 0, j = 0; i < n; i++)
    {
        if(!arr[i]){
            while(notRec[j] == -1){
                j++;
            }
            // cout<<endl<<notRec[j]<<endl;
            if((i+1) != notRec[j]){
                arr[i] = notRec[j];
                j++;
            } else {
                arr[i] = notRec[j+1];
                notRec[j+1] = -1;
            }
            // cout<<notRec[j]<<endl;
        }
    }
    
    
    return arr;

}

int main(){
    ll n;
    cin>>n;
    ll * arr = new ll[n];
    for (ll i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    arr = solve(arr, n);
    for (ll i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;
    
    return 0;
}