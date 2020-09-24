#include<bits/stdc++.h>
using namespace std;

int getRequiredTime(vector<string> & taskList, const int & cooldown){
    int n = taskList.size();
    if(cooldown<=0) return n-1;

    unordered_map<string, int> lastTime;

    int res = -1;

    for(int i = 0; i<n; i++){
        if(lastTime.count(taskList[i])){
            res = max(res+1, lastTime[taskList[i]]+cooldown);
        } else {
            res++;
        }
        lastTime[taskList[i]] = res;
    }

    if(res == -1) return 0;
    else return res;
}

int main(){
    // int n;
    // cin>>n;

    vector<string> taskList;
    int cooldown;



    taskList = {"A", "A", "A"};
    cooldown = 3;



    // for(auto & s:taskList) cin>>s;
    // cin>>cooldown;

    cout<<getRequiredTime(taskList, cooldown)<<endl;

    return 0;

}