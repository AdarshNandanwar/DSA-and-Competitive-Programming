//Merge Overlapping Intervals
 
#include<bits/stdc++.h>
using namespace std;
 
 
void mergeIntervals(vector<pair<int, int>> intervals){
    stack<pair<int, int>> s;
    
    sort(intervals.begin(), intervals.end());
 
    s.push(intervals[0]);
    for(int i=1; i<intervals.size(); i++){
        if(s.top().second < intervals[i].first){
            s.push(intervals[i]);
        }
        else{
            if(s.top().second < intervals[i].second){
                pair<int, int> temp = s.top();
                temp.second = intervals[i].second;
                s.pop();
                s.push(temp);
            }
        }
    }
 
    while(!s.empty()){
        cout<<"("<<s.top().first<<" "<<s.top().second<<")"<<endl;
        s.pop();
    }
 
}
 
int main(){
    int n;
    cin>>n;
 
    vector<pair<int, int>> intervals;
 
    for(int i=0; i<n; i++){
        int x, y;
        cin>>x>>y;
        intervals.push_back(make_pair(x, y));
    }
 
    mergeIntervals(intervals);
 
}