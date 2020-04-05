#include<bits/stdc++.h>
#include<map>
using namespace std;
typedef long long ll;

int main(){
    ll n, mh = 0;
    cin>>n;
    map<int, int> m;
    while(n--){
        ll temp;
        cin>>temp;
        m[temp]++;
        mh = max(mh, temp);
    }
    cout<<m[mh]<<endl;
    return 0;
}
