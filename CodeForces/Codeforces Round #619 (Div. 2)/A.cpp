#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;

void swap(char & a, char & b){
    char temp = a;
    a = b;
    b = temp;
}

void solve(){

    string s1, s2, s3;
    cin>>s1>>s2>>s3;
    bool flag = true;
    for (ll i = 0; i < s1.length(); i++)
    {
        if(s1[i] == s3[i]){
            swap(s2[i], s3[i]);
        } else if (s2[i] == s3[i]){
            swap(s1[i], s3[i]);
        } else {
            flag = false;
            break;
        }
    }
    if(!flag){
        cout<<"NO"<<endl;
    } else {
        cout<<"YES"<<endl;
    }

}
 
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}