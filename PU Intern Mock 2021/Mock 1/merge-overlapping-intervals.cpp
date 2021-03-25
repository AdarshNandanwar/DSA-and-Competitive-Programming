// https://www.hackerrank.com/contests/intern-2020-bpgc/challenges/merge-overlapping-intervals

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

void solve(){
    ll n, start, end;
    cin>>n;
    vector<vector<ll>> in, ans;
    for(ll i = 0; i<n; i++){
        cin>>start>>end;
        in.push_back({start, end});
    }
    
    sort(in.begin(), in.end());
    
    start = in[0][0], end = in[0][1];
    for(ll i = 0; i<n; i++){
        if(in[i][0] <= end) end = max(end, in[i][1]);
        else {
            ans.push_back({start, end});
            start = in[i][0];
            end = in[i][1];
        }
    }
    ans.push_back({start, end});
    
    for(auto i:ans) cout<<i[0]<<" "<<i[1]<<endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ll t;
    cin>>t;
    while(t--) solve();
    return 0;
}
