#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, c;
        cin>>n;
        int * radiation = new int[n]();
        int * health = new int[n];
        int * start = new int[n]();
        int * end = new int[n]();
        for (int i = 0; i < n; i++)
        {
            cin>>c;
            int start_index = max(0, i-c);
            int end_index = min(n-1, i+c);
            start[start_index]++;
            end[end_index]++;
        }
        for (int i = 0; i < n; i++)
        {
            cin>>health[i];
        }
        
        for (int i = 1; i < n; i++)
        {
            start[i] +=start[i-1];
            end[i] +=end[i-1];
        }
        
        radiation[0] = start[0];
        for (int i = 1; i < n; i++)
        {
            radiation[i] = start[i] - end[i-1];
        }
        sort(health, health+n);
        sort(radiation, radiation+n);
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            if(health[i] != radiation[i]){
                flag = false;
                cout<<"NO"<<endl;
                break;
            }
        }
        if(flag){
            cout<<"YES"<<endl;
        }
        delete [] radiation;
        delete [] health;
        delete [] start;
        delete [] end;
    }
    return 0;
}