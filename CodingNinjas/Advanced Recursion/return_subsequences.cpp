#include<bits/stdc++.h>
using namespace std;

int subs(string s, string* output){
    if(s.empty()){
        output[0]="";
        return 1;
    }
    int size = subs(s.substr(1), output);
    for (int i = 0; i < size; i++)
    {
        output[size+i]=s[0]+output[i];
    }
    return 2*size;
}

int main(){
    string s;
    cin>>s;
    int max_size=pow(2,s.length());
    string* output = new string[max_size];
    int size = subs(s, output);
    for (int i = 0; i < size; i++)
    {
        cout<<output[i]<<endl;
    }
    
    delete[] output;
    return 0;
}