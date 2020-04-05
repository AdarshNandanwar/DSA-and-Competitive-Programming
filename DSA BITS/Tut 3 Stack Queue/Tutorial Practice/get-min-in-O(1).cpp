#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin>>n;
    stack<ll> st;
    ll min_d;
    for (ll i = 0; i < n; i++)
    {
        ll d;
        cin>>d;
        if(i == 0){
            st.push(d);
            min_d = d;
        } else {
            if(d < min_d){
                st.push(2*d-min_d);
                min_d = d;
            } else {
                st.push(d);
            }
        }
        cout<<"min: "<<min_d<<endl;
    }
    while(!st.empty()){
        if(st.top() < min_d){
            cout<<"ele: "<<min_d<<endl;
            min_d = 2*min_d-st.top();
            cout<<"min: "<<min_d<<endl;
        } else {
            cout<<"ele: "<<st.top()<<endl;
            cout<<"min: "<<min_d<<endl;
        }
        st.pop();
    }
    
    return 0;
}