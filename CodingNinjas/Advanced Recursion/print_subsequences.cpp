#include<bits/stdc++.h>
using namespace std;

void print_subsequences(string input, string output){
    if(input.empty()){
        cout<<output<<endl;
        return;
    }
    print_subsequences(input.substr(1), output);
    print_subsequences(input.substr(1), output+input[0]);
    return;
}

int main(){
    string input;
    cin>>input;
    string output="";
    print_subsequences(input, output);
    return 0;
}