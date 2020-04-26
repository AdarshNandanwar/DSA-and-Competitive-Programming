// Minimum Count
// Send Feedback
// Given an integer N, find and return the count of minimum numbers, sum of whose squares is equal to N.
// That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. Output will be 1, as 1 is the minimum count of numbers required.
// Note : x^y represents x raise to the power y.
// Input Format :
// Integer N
// Output Format :
// Required minimum count
// Constraints :
// 1 <= N <= 1000
// Sample Input 1 :
// 12
// Sample Output 1 :
// 3
// Sample Output 1 Explanation :
// 12 can be represented as :
// 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1
// 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 2^2
// 1^1 + 1^1 + 1^1 + 1^1 + 2^2 + 2^2
// 2^2 + 2^2 + 2^2
// As we can see, the output should be 3.
// Sample Input 2 :
// 9
// Sample Output 2 :
// 1

#include<bits/stdc++.h>
using namespace std;

int find_ans(int start, int num, int sum, int ** dp){
    if(sum == num){
        return 0;
    }
    if(sum > num || start == num){
        return num+1;
    }
    if(dp[start][sum] != -1){
        return dp[start][sum];
    }
    int option1 = find_ans(start + 1, num, sum, dp);
    int option2 = 1 + find_ans(start, num, sum + start*start, dp);
    int output = min(option1, option2);
    dp[start][sum] = output;
    return output;
}

int minCount(int n){
    
    /*  Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
    int ** dp = new int*[n];
    for (int i = 0; i < n; i++)
    {
        dp[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = -1;
        } 
    }
    
    int ans = find_ans(1, n, 0, dp);
    for (int i = 0; i < n; i++)
    {
        delete dp[i];
    }
    delete dp;
    return ans;
}

int main(){
    int n;
    cin>>n;
    cout<<minCount(n)<<endl;
    return 0;
}