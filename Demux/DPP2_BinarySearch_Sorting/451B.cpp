// https://codeforces.com/problemset/problem/451/B

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

void solve(){

    cin>>n;
    vector<int> v(n);
    for(auto & i:v) cin>>i;

    vector<int> vs(v);
    sort(vs.begin(), vs.end());

    int st = -1, end = -1;
    for(int i = 0; i<n; i++){
        if(v[i] != vs[i]){
            if(st == -1) st = i;
            end = i;
        }
    }

    if(st != -1) reverse(v.begin()+st, v.begin()+end+1);
    else{
        cout<<"yes\n1 1\n";
        return;
    }

    for(int i = 0; i<n; i++){
        if(v[i] != vs[i]) {
            cout<<"no\n";
            return;
        }
    }
    cout<<"yes\n"<<st+1<<" "<<end+1<<endl;
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