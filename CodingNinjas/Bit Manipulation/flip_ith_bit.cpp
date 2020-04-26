#include<bits/stdc++.h>
using namespace std;

int flipIthBit(int n, int i){
    return (n^(1<<i));
}

int main(){
    int n, i;
    cin>>n>>i;
    cout<<flipIthBit(n,i);
    return 0;
}