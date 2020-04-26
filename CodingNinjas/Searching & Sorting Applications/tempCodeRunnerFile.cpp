#include<bits/stdc++.h>
using namespace std;

bool check_distance(int* arr, int n, int min_dist, int c){
    int count=1, prev_pos=arr[0];
        
    for(int i=1; i<n; i++){
        if(arr[i]-prev_pos>=min_dist){
            count++;
            prev_pos=arr[i];
        }
    }
    if(count>=c){
        return true;
    }else{
        return false;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, c;
        cin>>n>>c;
        int* arr=new int[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        sort(arr, arr+n);
       
        int start=arr[0], end=arr[n-1], mid;
        while(start<=end){
            mid=start+((end-start)/2);

            if(check_distance(arr, n, mid, c)){
                start=mid+1;
            }else{
                end=mid-1;
            } 
        }
        cout<<end;
        delete[] arr;
    }
    return 0;
}