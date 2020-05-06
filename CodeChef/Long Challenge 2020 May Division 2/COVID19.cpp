#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

void solve(){

    cin>>n;
    ll * arr = new ll[n];
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    int min_len = INT_MAX, max_len = INT_MIN, cur_len = 1;
    sort(arr, arr+n);
    for(int i = 1;i<n; i++){
        if(arr[i]-arr[i-1] <= 2){
            cur_len++;
        } else {
            max_len = max(max_len, cur_len);
            min_len = min(min_len, cur_len);
            cur_len = 1;
        }
    }
    max_len = max(max_len, cur_len);
    min_len = min(min_len, cur_len);
    cout<<min_len<<" "<<max_len<<endl;
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