// http://codeforces.com/problemset/problem/1144/B

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

void solve(){

    cin>>n;
    vector<int> even, odd;
    int t, sum = 0;
    for(int i = 0; i<n; i++){
        cin>>t;
        if(t%2) odd.push_back(t);
        else even.push_back(t);
    }

    sort(even.begin(), even.end(), greater<int>());
    sort(odd.begin(), odd.end(), greater<int>());

    if(even.size() < odd.size()){
        for(int i = even.size()+1; i<odd.size(); i++) sum += odd[i];
    } else {
        for(int i = odd.size()+1; i<even.size(); i++) sum += even[i];
    }
    cout<<sum<<endl;
}
 
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 1;
    while(t--){
        solve();
    }
    return 0;
}