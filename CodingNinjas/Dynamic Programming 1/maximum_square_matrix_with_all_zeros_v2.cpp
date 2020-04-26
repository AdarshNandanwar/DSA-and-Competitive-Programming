// Maximum Square Matrix With All Zeros
// Send Feedback
// Given a n*m matrix which contains only 0s and 1s, find out the size of maximum square sub-matrix with all 0s. You need to return the size of square with all 0s.
// Input format :
// Line 1 : n and m (space separated positive integers)
// Next n lines : m elements of each row (separated by space).
// Output Format:
// Line 1 : Size of maximum square sub-matrix
// Sample Input :
// 3 3
// 1 1 0
// 1 1 1
// 1 1 1
// Sample Output :
// 1

#include<bits/stdc++.h>
using namespace std;

int findMaxSquareWithAllZeros(int** arr, int row, int col){
    int ** dp = new int*[row];
    for (int i = 0; i < row; i++)
    {
        dp[i] = new int[col];
    }
    
    int max_side = 0;
    for (int i = 0; i < col; i++)
    {
        if(arr[0][i] == 0){
            dp[0][i] = 1;
        }else{
            dp[0][i] = 0;
        }
        max_side = max(max_side, dp[0][i]);
    }
    for (int i = 0; i < row; i++)
    {
        if(arr[i][0] == 0){
            dp[i][0] = 1;
        }else{
            dp[i][0] = 0;
        }
        max_side = max(max_side, dp[i][0]);
    }
    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j < col; j++)
        {
            if(arr[i][j] == 1){
                dp[i][j] = 0;
            }else{
                dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
            }
            max_side = max(max_side, dp[i][j]);
        }
        
    }
    

    for (int i = 0; i < row; i++)
    {
        delete [] dp[i];
    }
    delete [] dp;
    return max_side;
}

int main(){
    int r,c;
    cin>>r>>c;
    int ** input = new int*[r];
    for (int i = 0; i < r; i++)
    {
        input[i] = new int[c];
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin>>input[i][j];
        }
        
    }
    
    cout<<findMaxSquareWithAllZeros(input, r, c)<<endl;
    for (int i = 0; i < r; i++)
    {
        delete [] input[i];
    }
    delete [] input;
    return 0;
}