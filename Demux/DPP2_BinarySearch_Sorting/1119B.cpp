// http://codeforces.com/problemset/problem/1119/B

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

// Method 1 (O(n2))

void solve(){

    int h, res = 0;
    cin>>n>>h;
    vector<int> v(n);
    for(auto & i:v) cin>>i;

    // insertion sort

    for(int i = 0; i<n; i++){
        int num = v[i], j = i-1, requiredH = 0;
        while(j>=0 and num > v[j]){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = num;   
        for(int k = 0; k<=i; k += 2) requiredH += v[k];     // no need to check the k+1 as v[0,i] is sorted in descending order
        if(requiredH <= h) res = max(res, i+1);
        else break;
    }
    
    cout<<res<<endl;
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