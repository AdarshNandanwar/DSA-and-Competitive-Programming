#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, t;
    cin>>n>>t;
    string s;
    cin>>s;
    for (int i = 0; i < t; i++)
    {
        for (int i = 0; i < s.length()-1;)
        {
            if(s[i] == 'B' && s[i+1] == 'G'){
                s[i] = 'G';
                s[i+1] = 'B';
                i+=2;
            } else {
                i++;
            }
        }
    }
    cout<<s<<endl;    
    return 0;
}