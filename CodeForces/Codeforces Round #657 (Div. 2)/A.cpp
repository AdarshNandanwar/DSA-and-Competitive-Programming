#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

void solve(){

    // code
    cin>>n;
    string s, p = "abacaba";
    cin>>s;
    int i, j, l;
    for(i = 0; i+6<n; i++){
        string t(s);
        for(j = 0; j<7; j++){
            if(t[i+j] == p[j]){
                continue;
            } else if(t[i+j] == '?'){
                t[i+j] = p[j];
            } else {
                break;
            }
        }
        if(j == 7) {
            int count = 0;
            for(int k = 0; k+6<n; k++){
                for(l = 0; l<7; l++){
                    if(t[k+l] != p[l]){
                        break;
                    }
                }
                if(l == 7) {
                    count++;
                }
            }
            if(count == 1){
                cout<<"Yes\n";
                for(int k = 0; k<n; k++){
                    cout<<(t[k] == '?' ? 'd' : t[k]);
                }
                cout<<endl;
                return;
            }
        }
    }
    cout<<"No\n";

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