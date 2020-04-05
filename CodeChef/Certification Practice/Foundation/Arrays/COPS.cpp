#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int m, x, y;
        cin>>m>>x>>y;
        int span = x*y;
        bool * safe = new bool[101];
        for (int i = 0; i < 101; i++)
        {
            safe[i] = true;
        }
        for (int i = 0; i < m; i++)
        {
            int temp;
            cin>>temp;
            int a = ((temp-span)>0)?(temp-span):1;
            int b = ((temp+span)<100)?(temp+span):100;
            for (int i = a; i <= b ; i++)
            {
                safe[i] = false;
            }
        }
        int count = 0;
        for (int i = 1; i < 101; i++)
        {
            if(safe[i]){
                count++;
            }
        }
        cout<<count<<endl;
        
        
    }
    return 0;
}