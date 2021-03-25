#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

void solve(){

    ll k;
    cin>>n>>k;
    string s;
    cin>>s;

    ll count = 0, first = 0, last = s.length()-1;

    for(int i = 0; i<s.length(); i++){
        if(s[i] == '*'){
            s[i] = 'x';
            first = i;
            count++;
            break;
        }
    }

    for(int i = s.length()-1; i>=0; i--){
        if(s[i] == 'x'){
            last = i;
            break;
        }
        if(s[i] == '*'){
            s[i] = 'x';
            count++;
            last = i;
            break;
        }
    }

    ll j = 0, i = 0;
    for(i = first; i<last;){
        for(j = min(i+k, last); j>i; j--){
            if(s[j] == 'x'){
                cout<<count<<endl;
                return;
            }
            if(s[j] == '*'){
                s[j] = 'x';
                count++;
                break;
            }
        }

        i = j;
    }

    cout<<count<<endl;
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