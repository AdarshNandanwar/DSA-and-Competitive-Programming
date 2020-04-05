#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll a, b, c, r;
        cin>>a>>b>>c>>r;
        ll left = c-r, right = c+r;
        if(a>b){
            ll temp;
            temp = b;
            b = a;
            a = temp;
        }
        // cout<<a<<" "<<b<<" "<<left<<" "<<right<<endl;
        if(left<=a && b<=right){
            cout<<0<<endl;
        } else if(left >= b || right <=a){
            cout<<b-a<<endl;
        } else if(left<b && a<=left){
            if(right>=b){
                cout<<left-a<<endl;
            } else {
                cout<<b-right+left-a<<endl;
            }
        } else {
            cout<<b-right<<endl;
        }
    }
    return 0;
}