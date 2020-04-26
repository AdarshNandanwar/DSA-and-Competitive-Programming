#include<bits/stdc++.h>
using namespace std;

// int clearFromLSB(int n, int i){
//     return (n&(-(1<<(i+1))));
// }

int clearFromLSB(int n, int i){
    return n & ~((1<<(i+1))-1);
}
int main(){
    int n, i;
    cin>>n>>i;
    cout<<clearFromLSB(n, i)<<endl;
    return 0;
}