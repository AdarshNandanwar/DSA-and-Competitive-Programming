#include<bits/stdc++.h>
using namespace std;

bool isPowOf2(int n){
    return ((n&(n-1)) == 0);
}

int main(){
    int n;
    cin>>n;
    cout<<(isPowOf2(n)?"Power of 2":"Not a a power of 2")<<endl;
    return 0;
}