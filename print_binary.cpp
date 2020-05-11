#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

void printBinary(unsigned n) 
{
    if (n > 1) 
        printBinary(n/2);
    cout << n % 2; 
} 
 
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;
    printBinary(n);
}
