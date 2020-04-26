// Charlie and Pilots
// Send Feedback
// Charlie acquired airline transport company and to stay in business he needs to lower the expenses by any means possible. There are N pilots working for his company (N is even) and N/2 plane crews needs to be made. A plane crew consists of two pilots - a captain and his assistant. A captain must be older than his assistant. Each pilot has a contract granting him two possible salaries - one as a captain and the other as an assistant. A captain's salary is larger than assistant's for the same pilot. However, it is possible that an assistant has larger salary than his captain. Write a program that will compute the minimal amount of money Charlie needs to give for the pilots' salaries if he decides to spend some time to make the optimal (i.e. the cheapest) arrangement of pilots in crews.
// Input
// The first line of input contains integer N, 2 ≤ N ≤ 10,000, N is even, the number of pilots working for the Charlie's company. The next N lines of input contain pilots' salaries. The lines are sorted by pilot's age, the salaries of the youngest pilot are given the first. Each of those N lines contains two integers separated by a space character, X i Y, 1 ≤ Y < X ≤ 100,000, a salary as a captain (X) and a salary as an assistant (Y).
// Output
// The first and only line of output should contain the minimal amount of money Charlie needs to give for the pilots' salaries. 
// Sample Input
// 4 
// 5000 3000 
// 6000 2000 
// 8000 1000 
// 9000 6000 
// Sample Output
// 19000 

#include <bits/stdc++.h>
using namespace std;

int solve(int * c, int * a, int n, int x, int ** dp){
    if(n == 0){
        return 0;
    }
    if(dp[n][x] != -1){
        return dp[n][x];
    }
    int ans;
    if(x == 0){
        ans = a[0] + solve(c+1, a+1, n-1, 1, dp);
    } else if(x == n){
        ans = c[0] + solve(c+1, a+1, n-1, x-1, dp);
    } else {
        int option1 = a[0] + solve(c+1, a+1, n-1, x+1, dp);
        int option2 = c[0] + solve(c+1, a+1, n-1, x-1, dp);
        ans = min(option1, option2);
    }
    dp[n][x] = ans;
    return ans;
}

int  pilots(int * c, int * a, int n){
    int ** dp = new int*[n+1];
    for (int i = 0; i < n+1; i++)
    {
        dp[i] = new int[n/2+1];
        for (int j = 0; j < n/2+1; j++)
        {
            dp[i][j] = -1;
        }
    }
    int ans = solve(c, a, n, 0, dp);
    for (int i = 0; i < n+1; i++)
    {
        delete [] dp[i];
    }
    delete [] dp;
    return ans;
}

int main()
{
    int n;
    cin>>n;
    int * c = new int[n];
    int * a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>c[i]>>a[i];
    }
    cout<<pilots(c, a, n)<<endl;
    
    delete [] c;
    delete [] a;
    return 0;
}