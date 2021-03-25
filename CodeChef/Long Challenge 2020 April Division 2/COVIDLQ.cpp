#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;

string solve(){

    cin>>n;
    ll data, count = 5;
    vector<ll> v(n);
    while(n--){
        cin>>data;
        v.push_back(data);
    }
    for(auto itr:v){
        if(itr){
            if(count<5){
                return "NO";
            }
            count = 0;
        }else{
            count++;
        }
    }
    return "YES";
}
 
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;;
    }
    return 0;
}