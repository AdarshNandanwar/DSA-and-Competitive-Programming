#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;

bool comparator(string a, string b){
    if(a.length() != b.length()){
        return a.length() > b.length();
    } else {
        for (ll i = 0; i < a.length(); i++)
        {
            if(a[i] == b[i]){
                continue;
            } else {
                return a[i] > b[i];
            }
        }
        return true;
    }
}

void solve(){

    cin>>n;
    string * arr = new string[n];
    for (ll i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    sort(arr, arr+n, comparator);
    for (ll i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;
    
    delete [] arr;
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