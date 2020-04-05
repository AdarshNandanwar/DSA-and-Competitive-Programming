#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int * arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        bool flag;
        if(arr[0] == 1){
            flag = true;
        } else {
            flag = false;
        }
        int prev = 1;
        for (int i = 0; i < n/2; i++)
        {
            if(arr[i]-prev>1 || arr[i]<prev){
                flag = false;
                break;
            }
            if(arr[i]-prev==1){
                prev = arr[i];
            }
            if(arr[i] != arr[n-i-1]){
                flag = false;
                break;
            }
            // cout<<":"<<prev<<endl;
        }
        // if(n%2 && (arr[n/2]-prev>1 || arr[n/2]<prev)){
        //     flag = false;
        // }
        if(n%2 && (arr[n/2]!=7)){
            flag = false;   
        }
        if(n%2==0 && prev!=7){
            flag = false;
        }
        if(flag){
            cout<<"yes"<<endl;
        } else {
            cout<<"no"<<endl;
        }
        delete [] arr;
    }
    return 0;
}