#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string str;
    cin>>str;
    ll i =0;
    while(str[i]!='\0'){
        if( str[i] == 'a' || 
            str[i] == 'e' || 
            str[i] == 'i' || 
            str[i] == 'o' || 
            str[i] == 'y' || 
            str[i] == 'u' || 
            str[i] == 'A' || 
            str[i] == 'E' || 
            str[i] == 'I' || 
            str[i] == 'Y' || 
            str[i] == 'O' || 
            str[i] == 'U'
            ){
            str = str.substr(0, i)+str.substr(i+1);
        } else {
            if(str[i] < 97){
                str[i] += 32;
            }
            str = str.substr(0, i)+'.'+str.substr(i);
            i += 2;
        }
    }
    cout<<str<<endl;

    return 0;
}