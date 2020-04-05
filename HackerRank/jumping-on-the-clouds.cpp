#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, count = 0;
    cin>>n;
    int * arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int pos = 0;
    if(n == 2){
        count = 1;
    } else {
       while(pos!=n-1)
        {
            if(arr[pos+2] == 0){
                pos += 2;
            } else {
                pos++;
            }
            count++;
        } 
    }
    
    cout<<count<<endl;
    return 0;
}