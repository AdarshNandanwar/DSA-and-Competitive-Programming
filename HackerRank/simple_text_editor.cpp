#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll q;
    cin>>q;
    stack<string> s;
    s.push("");
    while(q--){
        ll o;
        cin>>o;
        switch(o){
            case 1: {string w;
                    cin>>w;
                    s.push(s.top()+w);
                    break;}
            case 2: {ll x;
                    cin>>x;
                    s.push(s.top().substr(0, s.top().length()-x));
                    break;}
            case 3: {ll x;
                    cin>>x;
                    cout<<s.top()[x-1]<<endl;
                    break;}
            case 4: {s.pop();
                    break;}
            default: break;
        }
    }
    return 0;
}