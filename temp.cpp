#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    // double a = (double)0.0000001, b = 8.234;
    // cout<<a<<endl;
    // cout<<stod("1")<<endl;
    // cout<<stod("1.0")<<endl;
    // cout<<stod("1.1")<<endl;

    double res = 0;

    for(double i = 1; i<=2000; i++){
        res += (i*i);
    }
    cout<<res<<endl;

    return 0;
}