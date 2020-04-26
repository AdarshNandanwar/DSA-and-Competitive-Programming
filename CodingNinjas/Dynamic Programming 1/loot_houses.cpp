// Loot Houses
// Send Feedback
// A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses. Find the maximum amount of money he can loot.
// Input Format
// Line 1 : An integer N 
// Line 2 : N spaced integers denoting money in each house
// Output Format
//  Line 1 : Maximum amount of money looted
// Input Constraints
// 1 <= n <= 10^4
// 1 <= A[i] < 10^4
// Sample Input :
// 6
// 5 5 10 100 10 5
// Sample Output 1 :
// 110

#include<bits/stdc++.h>
using namespace std;

int solve(int * arr, int n, int * dp){
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return arr[0];
    }
    if(dp[n] != -1){
        return dp[n];
    }
    int option1 = arr[0] + solve(arr + 2, n - 2, dp);
    int option2 = solve(arr + 1, n - 1, dp);
    int output = max(option1, option2);
    dp[n] = output;
    return output;
}

int getMaxMoney(int arr[], int n){

	/*Write your code here.
	 *Don’t write main(). 
	 *Don’t take input, it is passed as function argument.
	 *Don’t print output.
	 *Taking input and printing output is handled automatically.
         */ 
    int * dp = new int[n+1];
    for (int i = 0; i < n+1; i++)
    {
        dp[i] = -1;
    }
    int ans = solve(arr, n, dp);
    delete [] dp;
    return ans;
}

int main(){
    int n;
    cin>>n;
    int * arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<getMaxMoney(arr, n)<<endl;
    delete [] arr;
    return 0;
}