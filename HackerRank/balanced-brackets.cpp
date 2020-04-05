#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        stack<char> st;
        bool flag = true;
        for (ll i = 0; i < s.length(); i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            } else if (st.size() && ((s[i]==')' && st.top()=='(') || (s[i]=='}' && st.top()=='{') || (s[i]==']' && st.top()=='['))){
                st.pop();
            } else {
                cout<<"NO"<<endl;
                flag = false;
                break;
            }
        }
        if(flag && st.size()){
            cout<<"NO"<<endl;
            flag = false;
        }
        if(flag){
            cout<<"YES"<<endl;
        }
    }
    return 0;
}