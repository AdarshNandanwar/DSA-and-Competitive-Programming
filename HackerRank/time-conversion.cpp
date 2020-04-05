#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin>>s;
    if(s[8]=='A'){
        int a;
        a = stoi(s.substr(0,2));
        if(a == 12 ){
            a-=12;
        }
        if(a<10){
            cout<<0;
        }
        cout<<to_string(a)<<s.substr(2,6)<<endl;
    } else {
        int a;
        a = stoi(s.substr(0,2));
        if(a != 12 ){
            a+=12;
        }
        if(a<10){
            cout<<0;
        }
        cout<<to_string(a)<<s.substr(2,6)<<endl;
    }
    return 0;
}