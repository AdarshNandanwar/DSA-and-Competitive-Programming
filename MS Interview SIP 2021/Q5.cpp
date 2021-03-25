#include<bits/stdc++.h>
using namespace std;

int getAverage(vector<vector<int>> & entries, int time){
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> entries(n, vector<int>(3));

    for(auto & entry:entries){
        // { entry = 0/ exit = 1, time, weight}
        cin>>entry[0]>>entry[1]>>entry[2];
    }

    // {weight, count}
    vector<pair<int, int>> vec(24, {0, 0});

    




    cout<<getAverage(entries, time)<<endl;
    
    return 0;

}