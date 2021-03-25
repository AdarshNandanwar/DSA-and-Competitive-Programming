#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

void solve(){
    int t;
    cin>>n;
    vector<int> v;
    unordered_set<int> s;
    for(int i = 0; i<2*n; i++){
        cin>>t;
        if(!s.count(t)){ 
            s.insert(t); 
            v.push_back(t);
        }
    } 
    
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<endl;

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