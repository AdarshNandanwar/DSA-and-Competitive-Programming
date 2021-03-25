// Design a stack that supports getMin() in O(1) time and O(1) extra space

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin>>s;
    stack<string> st;
    for (ll i = s.length()-1; i >= 0; i--)
    {
        if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^'){
            string b1 = st.top();
            st.pop();
            string b2 = st.top();
            st.pop();
            st.push(b1+b2+s[i]);
        } else {
            st.push(s.substr(i,1));
        }
    }
    string ans = st.top();
    cout<<ans<<endl;
}
