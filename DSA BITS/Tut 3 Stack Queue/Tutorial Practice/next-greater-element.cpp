#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin>>n;
    stack<ll> st;
    for (ll i = 0; i < n; i++)
    {
        ll ele;
        cin>> ele;
        if( i == 0){
            st.push(ele);
        } else {
            while(!st.empty() && st.top() < ele){
                cout<<st.top()<<" -- "<<ele<<endl;
                st.pop();
            }
            st.push(ele);
        }
    }
    while(!st.empty()){
        cout<<st.top()<<" -- "<<-1<<endl;
        st.pop();
    }
    
    return 0;
}