#include<bits/stdc++.h>
using namespace std;

int main(){
    string input;
    cin>>input;
    for (int i = 0; i < input.length();)
    {
        if(tolower(input[i]) == 'a' || tolower(input[i]) == 'e' || tolower(input[i]) == 'i' || tolower(input[i]) == 'o' || tolower(input[i]) == 'u' || tolower(input[i]) == 'y') {
            input = input.substr(0, i) + input.substr(i+1);
        } else {
            if(65<=input[i] && input[i]<=90){
                input[i]+=32;
            }
            input = input.substr(0,i) + "." + input.substr(i);
            i+=2;
        }
    }
    cout<<input<<endl;
    return 0;
}