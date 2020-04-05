#include<bits/stdc++.h>
using namespace std;

int helper(string path, int current_plus, int plus){
    if(path.length() == 0){
        if(current_plus == plus){
            return 1;
        } else {
            return 0;
        }
    }
    if(path[0] == '+'){
        return helper(path.substr(1), current_plus+1, plus);
    }
    if(path[0] == '-'){
        return helper(path.substr(1), current_plus, plus);
    }
    int ans = 0;
    ans += helper(path.substr(1), current_plus+1, plus);
    ans += helper(path.substr(1), current_plus, plus);
    return ans;    
}

int main(){
    string cpath, path;
    cin>>cpath;
    cin>>path;
    int plus = 0;
    for (int i = 0; i < cpath.length(); i++)
    {
        if(cpath[i] == '+')
        plus++;
    }
    int blank = 0;
    for (int i = 0; i < path.length(); i++)
    {
        if(path[i] == '?'){
            blank++;
        }
    }
    
    double ans = helper(path, 0, plus);
    cout<<ans/(1<<blank)<<endl;
    return 0;
}