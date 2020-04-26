// Number Of Balanced BTs
// Send Feedback
// Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
// This number can be huge, so return output modulus 10^9 + 7.
// Write a simple recursive solution.
// Input Format :
// Integer h
// Output Format :
// Count % 10^9 + 7
// Input Constraints :
// 1 <= h <= 40
// Sample Input 1:
// 3
// Sample Output 1:
// 15
// Sample Input 2:
// 4
// Sample Output 2:
// 315

#include<bits/stdc++.h>
using namespace std;

long long recurse(long long h){
    if(h==0){
        return 1;
    } else if (h==1){
        return 1;
    }
    long long x=recurse(h-1), y=recurse(h-2);
    return ((x*x)%1000000007 + (2*((x*y)%1000000007))%1000000007)%1000000007;
}

int balancedBTs(int h) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return the output and don’t print it.
  */
   return recurse(h);
}

int main(){
    int h;
    cin>>h;
    cout<<balancedBTs(h);
    return 0;
}