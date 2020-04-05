#include<bits/stdc++.h>
using namespace std;
 
bool customCompare(const pair<int, int> &a, const pair<int, int> &b){
    if(a.second != b.second){
        return a.second>b.second;
    } else {
        return a.first<b.first;
    }
}
 
int main(){
    int n;
    cin>>n;
 
    vector<pair<int, int>> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i].first>>v[i].second;
    }
 
    sort(v.begin(), v.end(), customCompare);
 
    cout<<endl;
    for(int i=0; i<n; i++)
        cout<<v[i].first<<" "<<v[i].second<<endl;
    
}