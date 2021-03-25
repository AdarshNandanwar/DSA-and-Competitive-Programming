#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

string solve(string s){
    string ans = "";
    int n = s.length();
    if(n%2){
        string s1 = s.substr(0, n/2);
        string s1Rev = s1;
        string s2 = s.substr((n/2+1), n);
        reverse(s1Rev.begin(), s1Rev.end());
        if(s1Rev > s2){
            ans = s1 + s[n/2] + s1Rev;
            return ans;
        } else {
            int i;
            for(i = n/2; i>=0; i--){
                if(s[i]!='9'){
                    break;
                } else {
                    s[i] = '0';
                    if(i!=(n/2)){
                        s1[i] = '0';
                        s1Rev[s1.length()-i-1] = '0';
                    }
                }
            }
            if(i < 0){
                for(i = 0; i<=n; i++){
                    if(i == 0 || i == n){
                        ans += '1';
                    } else {
                        ans += '0';
                    }
                }
                return ans;
            } else if(i == n/2){
                s[n/2]++;
                ans = s1 + s[n/2] + s1Rev;
            } else {
                s1[i]++;
                s1Rev[s1.length()-i-1]++;
                ans = s1 + s[n/2] + s1Rev;
                return ans;
            }
        }
    } else {
        string s1 = s.substr(0, n/2);
        string s1Rev = s1;
        string s2 = s.substr(n/2, n);
        reverse(s1Rev.begin(), s1Rev.end());
        if(s1Rev > s2){
            ans = s1 + s1Rev;
            return ans;
        } else {
            int i;
            for(i = (n/2)-1; i>=0; i--){
                if(s[i]!='9'){
                    break;
                } else {
                    s[i] = '0';
                    s1[i] = '0';
                    s1Rev[s1.length()-i-1] = '0';
                }
            }
            if(i < 0){
                for(i = 0; i<=n; i++){
                    if(i == 0 || i == n){
                        ans += '1';
                    } else {
                        ans += '0';
                    }
                }
                return ans;
            } else {
                s1[i]++;
                s1Rev[s1.length()-i-1]++;
                ans = s1 + s1Rev;
                return ans;
            }
        }
    }
    return ans;
}
 
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;
    cout<<solve(s)<<endl;
    return 0;
}