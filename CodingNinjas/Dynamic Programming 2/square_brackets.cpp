// Square Brackets
// Send Feedback
// You are given:
// a positive integer n,
// an integer k, 1<=k<=n,
// an increasing sequence of k integers 0 < s1 < s2 < ... < sk <= 2n.
// What is the number of proper bracket expressions of length 2n with opening brackets appearing in positions s1, s2,...,sk?
// Illustration
// Several proper bracket expressions:
// [[]][[[]][]] 
// [[[][]]][][[]]
// An improper bracket expression:
// [[[][]]][]][[]]
// There is exactly one proper expression of length 8 with opening brackets in positions 2, 5 and 7.
// Task
// Write a program which for each data set from a sequence of several data sets:
// 1. reads integers n, k and an increasing sequence of k integers from input,
// 2. computes the number of proper bracket expressions of length 2n with opening brackets appearing at positions s1,s2,...,sk,
// 3. writes the result to output.
// Input
// The first line of the input file contains one integer d, 1 <= d <= 10, which is the number of data sets. The data sets follow. Each data set occupies two lines of the input file. The first line contains two integers n and k separated by single space, 1 <= n <= 19, 1 <= k <= n. The second line contains an increasing sequence of k integers from the interval [1;2n] separated by single spaces.
// Output
// The i-th line of output should contain one integer - the number of proper bracket expressions of length 2n with opening brackets appearing at positions s1, s2,...,sk.
// Sample Input
// 5 
// 1 1 
// 1 
// 1 1 
// 2 
// 2 1 
// 1 
// 3 1 
// 2 
// 4 2 
// 5 7 
// Sample Output
// 1 
// 0 
// 2 
// 3 
// 2 

#include <bits/stdc++.h>
using namespace std;

void solve(int * arr, int n, int state, int & count){
    if(n == 0){
        if(state == 0){
            count++;
        }
        return;
    }
    
    if(arr[0] == 0){
        solve(arr+1, n-1, state+1, count);
        if(state > 0){
            solve(arr+1, n-1, state-1, count);
        }
    } else {
        solve(arr+1, n-1, state+1, count);
    }
    return;
}

int brackets(int * arr, int n){
    int state = 0, count = 0;
    solve(arr, n, state, count);
    return count;
}

int main()
{
    int t, n, k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        int pos;
        int * arr = new int[2*n]();
        for (int i = 0; i < k; i++)
        {
            cin>>pos;
            arr[pos-1] = 1;
        }
        cout<<brackets(arr, 2*n)<<endl;
        delete [] arr;
    }
    return 0;
}