//Prefix to Postfix conversion
 
#include<bits/stdc++.h>
using namespace std;
 
bool isOperator(string s){
    if(s == "+" || s == "-" || s == "*" || s == "/")
        return true;
    return false;
}
 
string preToIn(string exp){
    stack<string> s;
    int len = exp.size();
 
    for(int i = len-1; i>=0; i--){
        string temp = string(1, exp[i]);
        if(isOperator(temp)){
            string s1 = s.top();
            s.pop();
            string s2 = s.top();
            s.pop();
            string res = s1 + s2 + temp;
            s.push(res);
        }
        else{
            s.push(temp);
        }
 
    }
 
    return s.top();
 
 
}
 
int main(){
    string s;
    cin>>s;
 
    string ans = preToIn(s);
 
    cout<<ans<<endl;
    return 0;
 
}