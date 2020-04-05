#include<bits/stdc++.h>
using namespace std;

//currently gives the minimum length required instead of minimum unused length
int findLength(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 2;
    }
    if(n%2){
        return n+1+2*findLength(n/2);
    } else {
        return n+1+findLength(n/2)+findLength(n/2-1);
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        int len = findLength(n);
        if(m>=len){
            cout<<m-len<<endl;
        } else {
            cout<<-1;
        }
    }
    return 0;
}