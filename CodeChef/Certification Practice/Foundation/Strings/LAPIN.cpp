#include<bits/stdc++.h>
#include<map>
using namespace std;
typedef long long ll;

int main(){
    ll t;
    cin>>t;
    while(t--){
        string s;
        map<char,ll> m1, m2;
        
        cin>>s;
        for (ll i = 0; i < s.length()/2; i++)
        {
            m1[s[i]]++;
        }
        for (ll i = (s.length()+1)/2; i < s.length(); i++)
        {
            m2[s[i]]++;
        }
        cout<<(m1==m2?"YES":"NO")<<endl;
    }

    return 0;
}