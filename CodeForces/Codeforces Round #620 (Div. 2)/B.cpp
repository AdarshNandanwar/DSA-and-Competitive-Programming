#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m;

bool isPalindrome(string s){
    ll i = 0, j = s.length()-1;
    while(i<=j){
        if(s[i] != s[j]){
            return false;
        }
        i++; j--;
    }
    return true;
}
 
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    vector<string> v;
    map<string, ll> m;
    for (ll i = 0; i < n; i++)
    {
        string s;
        cin>>s;
        v.push_back(s);
        m[s]++;
    }
    sort(v.begin(), v.end());
    string ansString, centerString = "";
    bool isCenterIncluded = false;
    for (ll i = 0; i < n; i++)
    {
        reverse(v[i].begin(), v[i].end());
        string rev = v[i];
        reverse(v[i].begin(), v[i].end());
        if(!isCenterIncluded && isPalindrome(v[i])){
            centerString = v[i];
            isCenterIncluded = true;
        } else if(m[v[i]] && m[rev]){
            if(isPalindrome(v[i])){
                if(m[v[i]] >1){
                    m[v[i]] -= 2;
                    ansString += v[i];
                }
            } else {
                m[rev]--;
                m[v[i]]--;
                ansString += v[i];
            }
            continue;
        }
    }
    string finalString = ansString;
    reverse(ansString.begin(), ansString.end());
    finalString += centerString;
    finalString += ansString;
    cout<<finalString.length()<<endl;
    cout<<finalString<<endl;
    return 0;
}