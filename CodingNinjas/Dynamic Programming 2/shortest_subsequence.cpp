// Shortest Subsequence
// Send Feedback
// Gary has two string S and V. Now Gary wants to know the length shortest subsequence in S such that it is not a subsequence in V.
// Note: input data will be such so there will always be a solution.
// Input Format :
// Line 1 : String S of length N (1 <= N <= 1000)
// Line 2 : String V of length M (1 <= M <= 1000)
// Output Format :
// Length of shortest subsequence in S such that it is not a subsequence in V
// Sample Input :
// babab
// babba
// Sample Output :
// 3

#include<bits/stdc++.h>
using namespace std;

int find_ans(string s1, string s2, int l1, int l2, int ** dp){
    if(l2 == 0 && l1 != 0){
        return 1;
    }
    if(l1 == 0){
        return 1001;
    }
    if(dp[l1][l2] != -1){
        return dp[l1][l2];
    }
    int ans, option1 , option2;
    int pos = s2.find(s1[0]);
    option1 = find_ans(s1.substr(1), s2, l1-1, l2, dp);
    if(pos == std::string::npos){
        option2 = 1;
    } else {
        option2 = 1 + find_ans(s1.substr(1), s2.substr(pos+1), l1-1, l2-pos-1, dp);
    }
    ans = min(option1, option2);
    dp[l1][l2] = ans;
    return ans;
}

int solve(string S,string V)
{
    int l1 = S.length(), l2 = V.length();
    int ** dp = new int*[l1+1];
    for (int i = 0; i < l1+1; i++)
    {
        dp[i] = new int[l2+1];
        for (int j = 0; j < l2+1; j++)
        {
            dp[i][j] = -1;
        }
    }
    
	int ans = find_ans(S, V, l1, l2, dp);

    for (int i = 0; i < l1+1; i++)
    {
        delete [] dp[i];
    }
    delete [] dp;
    return ans;
}

int main(){
    string s1, s2;
    cin>>s1>>s2;
    cout<<solve(s1, s2)<<endl;
    return 0;
}