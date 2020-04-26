// StairCase Problem
// Send Feedback
// A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return all possible number of ways.
// Time complexity of your code should be O(n).
// Input format :
// Integer n (No. of steps)
// Constraints :
// n <= 70
// Sample Input 1:
// 4
// Sample Output 1:
// 7


#include<bits/stdc++.h>
using namespace std;

long staircase(int n){
    /*  Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
    if(n == 0){
        return 1;
    }
    if(n == 1){
        return staircase(0);
    }
    if(n == 2){
        return staircase(0) + staircase(1);
    }
    return staircase(n-1)+staircase(n-2)+staircase(n-3);
}

int main(){
    int n;
    cin>>n;
    cout<<staircase(n)<<endl;
    return 0;
}