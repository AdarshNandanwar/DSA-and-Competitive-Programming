// Edit Distance - Problem
// Send Feedback
// Given two strings s and t of lengths m and n respectively, find the Edit Distance between the strings. Edit Distance of two strings is minimum number of steps required to make one string equal to other. In order to do so you can perform following three operations only :
// 1. Delete a character

// 2. Replace a character with another one

// 3. Insert a character
// Note - Strings don't contain spaces
// Input Format :
// Line 1 : String s
// Line 2 : String t
// Output Format :
// Line 1 : Edit Distance value
// Constraints
// 1<= m,n <= 20
// Sample Input 1 :
// abc
// dc
// Sample Output 1 :
// 2

#include<iostream>
#include<cstring>
using namespace std;

int solve(string s1, string s2, int l1, int l2, int current_l1, int current_l2, int ** dp){
    if(l1 == 0 || l2 == 0){
        return abs(current_l1 - current_l2);
    }
    if(s1[0] == s2[0]){
        return solve(s1.substr(1), s2.substr(1), l1-1, l2-1, current_l1, current_l2, dp);
    }
    if(dp[l1][l2] != -1){
        return dp[l1][l2];
    }
    int option1 = 1 + solve(s1, s2.substr(1), l1, l2-1, current_l1+1, current_l2, dp);
    int option2 = 1 + solve(s1.substr(1), s2.substr(1), l1-1, l2-1, current_l1, current_l2, dp);
    int option3 = 1 + solve(s1.substr(1), s2, l1-1, l2, current_l1-1, current_l2, dp);
    int ans = min(option1, min(option2, option3));
    dp[l1][l2] = ans;
    return ans;
}

int editDistance(string s1, string s2){

  /*  Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
   */
    int l1 = s1.length(), l2 = s2.length();
    int ** dp = new int*[l1+1];
    for (int i = 0; i < l1+1; i++)
    {
        dp[i] = new int[l2+1];
        for (int j = 0; j < l2+1; j++)
        {
            dp[i][j] = -1;
        }
    }
    
    int current_l1 = l1, current_l2 = l2;
    int ans = solve(s1, s2, l1, l2, current_l1, current_l2, dp);
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
    cout<<editDistance(s1, s2)<<endl;
    return 0;
}