#include<bits/stdc++.h>
using namespace std;

int getAverage(vector<vector<int>> & entries, int time){
    int sum = 0, count = 0;
    for(auto entry:entries){
        if(entry[0] <= time and time <= entry[1]){
            sum = sum+entry[2];
            count++;
        }
    }

    if(count == 0) return 0;
    else return sum/count;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> entries(n, vector<int>(3));

    for(auto & entry:entries){
        cin>>entry[0]>>entry[1]>>entry[2];
    }
    int time;
    cin>>time;

    cout<<getAverage(entries, time)<<endl;
    
    return 0;

}