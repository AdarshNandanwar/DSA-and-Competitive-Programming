#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        int x, y, k, n;
        cin>>x>>y>>k>>n;        //length, left pages, budget, no. fo notenbooks
        int pageReq = x-y;
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            int p, c;
            cin>>p>>c;
            if(p>=pageReq && c<=k){
                flag = false;
            }
        }
        if(flag){
            cout<<"UnluckyChef"<<endl;
        } else {
            cout<<"LuckyChef"<<endl;
        }
    }
    return 0;
}