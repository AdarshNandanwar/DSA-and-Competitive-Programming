#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int count = 0;
        string s;
        cin>>s;
        for (int i = 0; i < s.length(); i++)
        {
            if(s[i] == '1'){
                count++;
            }
        }
        if(count%2){
            cout<<"WIN"<<endl;
        } else {
            cout<<"LOSE"<<endl;
        }
    }
}