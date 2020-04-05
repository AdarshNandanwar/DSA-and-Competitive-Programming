#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        char arr[100];
        map<char, bool> m;
        for (ll i = 0; i < 100; i++)
        {
            arr[i] = '0';
        }
        ll j = 50;
        arr[j] = s[0];
        ll minIndex = j, maxIndex = j;
        m[s[0]] = true;
        bool isPossible  =true;
        for (ll i = 1; i < s.length(); i++)
        {
            if(s[i] == arr[j+1]){
                j++;
                minIndex = min(minIndex, j);
                continue;
            } else if (s[i] == arr[j-1]){
                j--;
                maxIndex = max(maxIndex, j);
                continue;
            } else if (!m[s[i]]){
                if(arr[j+1] == '0'){
                    arr[j+1] = s[i];
                    m[s[i]] = true;
                    j++;
                    maxIndex = max(maxIndex, j);
                    continue;
                } else if (arr[j-1] == '0'){
                    arr[j-1] = s[i];
                    m[s[i]] = true;
                    j--;
                    minIndex = min(minIndex, j);
                    continue;
                }
            }
            isPossible = false;
            break;
        }
        if(isPossible){
            cout<<"YES\n";
            for (ll i = minIndex; i <= maxIndex; i++)
            {
                cout<<arr[i];
            }
            for (ll i = 97; i <= 122; i++)
            {
                if(!m[(char)i]){
                    cout<<(char)i;
                }
            }
            
            cout<<endl;
        } else {
            cout<<"NO\n";
        }
        
    }
    return 0;
}