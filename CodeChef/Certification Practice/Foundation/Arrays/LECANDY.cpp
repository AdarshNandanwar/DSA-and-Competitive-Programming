#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, c;
        cin>>n>>c;
        int * arr = new int[n];
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin>>temp;
            sum+=temp;
        }
        if(sum>c){
            cout<<"No"<<endl;
        } else {
            cout<<"Yes"<<endl;
        }

    }
    return 0;
}