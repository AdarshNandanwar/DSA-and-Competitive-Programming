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
                    s2.push(x);
                    break;
            case 2: if(s1.empty()){
                        while(!s2.empty()){
                            s1.push(s2.top());
                            s2.pop();
                        }
                    }
                    s1.pop();
                    break;
            case 3: if(s1.empty()){
                        while(!s2.empty()){
                            s1.push(s2.top());
                            s2.pop();
                        }
                    }
                    cout<<s1.top()<<endl;
                    break;
        }
    }
    return 0;
}