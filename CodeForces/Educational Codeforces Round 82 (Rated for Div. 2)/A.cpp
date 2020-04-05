#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll t;
    cin>>t;
    while (t--){
        string s;
        cin>>s;
        bool firstOccured = false;
        ll first1 = -1;
        ll last1 = -1;
        ll * arr = new ll[s.length()]();
        if(s[0] == '0'){
            arr[0] = 1;
        }
        for (ll i = 0; i < s.length(); i++)
        {
            arr[i] = arr[i-1];
            if(s[i] == '0'){
                arr[i]++;
            }
        }
        
        for (ll i = 0; i < s.length(); i++)
        {
            if(s[i] == '1'){
                if(firstOccured){
                    last1 = i;
                } else {
                    firstOccured = true;
                    first1 = i;
                    last1 = i;
                }
            }
        }
        if(firstOccured){
            cout<<arr[last1]-arr[first1]<<endl;
        } else {
            cout<<0<<endl;
        }
    }
    
    return 0;
}