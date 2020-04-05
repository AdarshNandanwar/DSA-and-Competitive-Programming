#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    string s;
    while(t--){
        cin>>s;
        string ans = s.substr(0,1);
        if(s.length()>10){
            int n = (s.length()-2);
            string number;
            while(n){
                int last = n%10;
                number = (char)(last+48) + number;
                n/=10;
            }
            ans = ans + number;
            ans = ans + s[s.length()-1];
        } else {
            ans = s;
        }
        cout<<ans<<endl;
    }
    return 0;
}