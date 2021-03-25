#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    ll st, end, mid;
    cin>>st>>end;
    st++;
    ll n;
    cin>>n;
    string s;
    while(n-- and st<=end){
        mid = st+(end-st)/2;
        cout<<mid<<endl;
        cin>>s;
        if(s == "CORRECT") return;
        else if(s == "TOO_SMALL"){
            st = mid+1;
        } else if(s == "TOO_BIG"){
            end = mid-1;
        }
    }
}

int main(){
    ll t;
    cin>>t;
    while(t--) solve();
    return 0;
}