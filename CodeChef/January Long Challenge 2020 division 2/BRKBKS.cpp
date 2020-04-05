#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll s, w1, w2, w3;
        cin>>s>>w1>>w2>>w3;
        ll count = 0;
        stack<int> st;
        st.push(w1);
        st.push(w2);
        st.push(w3);
        while(!st.empty()){
            ll bal = s;
            count++;
            while(!st.empty() && st.top() <= bal){
                bal -= st.top();
                st.pop();
            }
        }
        cout<<count<<endl;
    }
    return 0;
}