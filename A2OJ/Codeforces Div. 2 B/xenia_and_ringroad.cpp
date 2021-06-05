#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, m, pos = 1, time = 0;
    cin>>n>>m;
    ll * arr = new ll[m];
    for (ll i = 0; i < m; i++)
    {
        cin>>arr[i];
        if(arr[i]>pos){
            time+=(arr[i]-pos);
        } else if (arr[i]<pos){
            time+=(arr[i]-pos+n);
        }
        pos = arr[i];
    }
    cout<<time<<endl;
    return 0;
}