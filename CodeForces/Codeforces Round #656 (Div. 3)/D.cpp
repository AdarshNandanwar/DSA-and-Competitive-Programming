#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

int helper(string & s, char c, int st, int end){

    if(st == end) return s[st]!=c;
    if(st>end or c>'z') return 10e6;

    int mid = st+(end-st)/2, first = 0, second = 0;
    for(int i = st; i<=mid; i++) if(s[i] != c) first++;
    for(int i = mid+1; i<=end; i++) if(s[i] != c) second++;
    return min(first+helper(s, c+1, mid+1, end), second+helper(s, c+1, st, mid));
}

void solve(){

    cin>>n;
    string s;
    cin>>s;

    cout<<helper(s, 'a', 0, n-1)<<endl;
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