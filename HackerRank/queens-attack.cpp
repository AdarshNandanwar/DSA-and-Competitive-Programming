#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, k, R, C, count = 0;
    map<pair<ll,ll>, ll> m;
    cin>>n>>k>>R>>C;
    R--;C--;
    while(k--){
        ll r, c;
        cin>>r>>c;
        r--; c--;
        m[make_pair(r,c)] = 1;
    }
    ll r, c;

    r = R; c = C;
    while(r > 0){
        r--;
        if(m[make_pair(r,c)]) break;
        count++;
    }

    r = R; c = C;
    while(c > 0){
        c--;
        if(m[make_pair(r,c)]) break;
        count++;
    }

    r = R; c = C;
    while(r < n-1){
        r++;
        if(m[make_pair(r,c)]) break;
        count++;
    }
    
    r = R; c = C;
    while(c < n-1){
        c++;
        if(m[make_pair(r,c)]) break;
        count++;
    }



    r = R; c = C;
    while(r > 0 && c > 0){
        r--; c--;
        if(m[make_pair(r,c)]) break;
        count++;
    }

    r = R; c = C;
    while(r > 0 && c < n-1){
        r--; c++;
        if(m[make_pair(r,c)]) break;
        count++;
    }

    r = R; c = C;
    while(r < n-1  && c < n-1){
        r++; c++;
        if(m[make_pair(r,c)]) break;
        count++;
    }
    
    r = R; c = C;
    while(r < n-1  && c > 0){
        r++; c--;
        if(m[make_pair(r,c)]) break;
        count++;
    }
    cout<<count<<endl;
    return 0;
}