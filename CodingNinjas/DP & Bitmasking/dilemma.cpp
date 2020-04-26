// Dilemma
// Send Feedback
// Abhishek, a blind man recently bought N binary strings all of equal length .A binary string only contains '0's and '1's . The strings are numbered from 1 to N and all are distinct, but Abhishek can only differentiate between these strings by touching them. In one touch Abhishek can identify one character at a position of a string from the set. Find the minimum number of touches T Abhishek has to make so that he learn that all strings are different .
// Constraints :
// 2<=N<=10
// 1<=|L|<=100 , L is length of the strings .
// Input Format:
// Line 1 : An Integer N, denoting the number of binary strings .
// Next N lines : strings of equal length
// Output Format:
// Return the minimum number of touches
// Sample Input :
// 2
// 111010
// 100100
// Sample Output :
// 2

#include<bits/stdc++.h>
using namespace std;

int solve(int n, vector<string> v, int mask, int pos, int ** dp){
    if(dp[mask][pos] != -1){
        return dp[mask][pos];
    }
    int ones = 0;
    for (int i = 0; i < n; i++)
    {
        if(mask&(1<<i)){
            ones++;
        }
    }
    if(ones <= 1){
        return 0;
    }
    if(v[0].length() <= pos){
        return 10000;
    }
    int mask0  = 0, mask1 = 0;
    for (int i = 0; i < n; i++)
    {
        if(mask&(1<<i)){
            if(v[n-i-1][pos] == '0'){
                mask0 = (mask0|(1<<i));
            } else {
                mask1 = (mask1|(1<<i));
            }
        }
    }
    int ans;
    int option1 = solve(n, v, mask0, pos+1, dp) + solve(n, v, mask1, pos+1, dp) + ones;
    int option2 = solve(n, v, mask, pos+1, dp);
    ans = min(option1, option2);
    dp[mask][pos] = ans;
    return ans;
}

int minimumTouchesRequired(int n, vector<string> v) {
    /* Don't write main().
     * Don't read input, they are passed as function arguments.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    int ** dp = new int*[1<<n];
    for (int i = 0; i < (1<<n); i++)
    {
        dp[i] = new int[v[0].length()+1];
        for (int j = 0; j < v[0].length()+1; j++)
        {
            dp[i][j] = -1;
        }        
    }
    
    int ans = solve(n, v, (1<<n)-1, 0, dp);

    for (int i = 0; i < (1<<n); i++)
    {
        delete [] dp[i];
    }
    delete [] dp;
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<string> input;
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin>>temp;
        input.push_back(temp);
    }
    cout<<minimumTouchesRequired(n, input)<<endl;
    return 0;
}