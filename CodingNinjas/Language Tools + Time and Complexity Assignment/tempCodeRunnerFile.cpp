#include<bits/stdc++.h>
using namespace std;

vector<int> longestSubsequence(int *arr, int n){
	// Write your code here
    sort(arr, arr+n);
    
    int count=1, max_count=-1, end=0;
    for(int i=1; i<n; i++){
        if(arr[i-1]+1==arr[i]){
            count++;
        }else{
            if(count>max_count){
                max_count=count;
                end=i;                    
            }
            count=1;
        }
    }
    vector<int> v;
    if(max_count==1){
        v.push_back(arr[0]);
        return v;
    }else{
        for(int i=max_count; i>0; i--){
            v.push_back(arr[end-i]);
        }
        return v;
    }
}