#include<bits/stdc++.h>
using namespace std;

int find_wait_time(int* open_time, int N, int arrival_time){
    if(binary_search(open_time, open_time+N, arrival_time)){
        int upper=upper_bound(open_time, open_time+N, arrival_time)-open_time;
        if(upper>=N){
            return -1;
        }
        if(upper%2){
            return 0;
        }else{
            return open_time[upper]-arrival_time;
        }
    }else{
        int lower=lower_bound(open_time, open_time+N, arrival_time)-open_time;
        if(lower>=N){
            return -1;
        }
        if(lower%2){
            return 0;
        }else{
            return open_time[lower]-arrival_time;
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        int N=2*n;
        int* open_time = new int[N];
        int* arrival_time = new int[m];
        for (int i = 0; i < N; i++)
        {
            cin>>open_time[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin>>arrival_time[i];
        }
        
        sort(open_time, open_time+N);
        for (int i = 0; i < m; i++)
        {
            cout<<find_wait_time(open_time, N, arrival_time[i])<<endl;
        }
        delete[] open_time;
        delete[] arrival_time;
    }
    return 0;
}