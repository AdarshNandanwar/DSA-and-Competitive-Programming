#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    
    ll t, n, X, Y;
    cin>>t;
    for(int k = 1; k<=t; k++){
        ll cost = 0;
        string s;
        cin>>X>>Y>>s;

        for(int i = 0; i<s.length(); i++){
            if(i != 0 and s[i] == '?'){
                s[i] = s[i-1];
            }
        }
        for(int i = s.length()-1; i>=0; i--){
            if(i != s.length()-1 and s[i] == '?'){
                s[i] = s[i+1];
            }
        }

        for(int i =1; i<s.length(); i++){
            if(s[i-1] == 'C' and s[i] == 'J') cost += X;
            if(s[i-1] == 'J' and s[i] == 'C') cost += Y;
        }
        
        cout<<"Case #"<<k<<": "<<cost<<endl;
    }
    
    return 0;
}