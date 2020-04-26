#include<bits/stdc++.h>
using namespace std;

bool check_distance(int* arr, int n, int min_dist, int c){

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return true;
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
            for (int i = 0; i < n; i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
            check_distance(arr, n, mid, c);
            start++;
            // if(check_distance(arr, n, mid, c)){
            //     start=mid+1;
            // }else{
            //     end=mid-1;
            // } 
            
        }
        cout<<end;
        delete[] arr;
        
    }
    return 0;
}