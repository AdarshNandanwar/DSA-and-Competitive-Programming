#include<bits/stdc++.h>
using namespace std;

bool isOdd(int n){
    return n&1;
}

int main(){
    int n;
    cin>>n;
    cout<<(isOdd(n)?"Odd":"Even");
    return 0;
}