// http://codeforces.com/problemset/problem/940/A

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

void solve(){

    cin>>n;
    int d;
    cin>>d;
    vector<int> v(n, 0);
    for(int i = 0; i<n; i++){
        cin>>v[i];
    }

    sort(v.begin(), v.end());

    int p1 = 0, p2 = 0, maxWidth = 0;
    while(p2<n){
        while(v[p2]-v[p1] > d){
            p1++;
        }
        maxWidth = max(maxWidth, p2-p1+1);
        p2++;
    }

    cout<<n-maxWidth<<endl;

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