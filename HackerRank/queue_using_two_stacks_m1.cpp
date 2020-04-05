#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin>>n;
    stack<ll> s1, s2;
    while(n--){
        ll type;
        cin>>type;
        switch(type){
            case 1: ll x;
                    cin>>x;
                    while(!s1.empty()){
                        s2.push(s1.top());
                        s1.pop();
                    }
                    s2.push(x);
                    while(!s2.empty()){
                        s1.push(s2.top());
                        s2.pop();
                    }
                    break;
            case 2: s1.pop();
                    break;
            case 3: cout<<s1.top()<<endl;
                    break;
        }
    }
    return 0;
}