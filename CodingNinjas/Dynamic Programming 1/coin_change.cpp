// Coin Change Problem
// Send Feedback
// You are given an infinite supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, in which you can make change for Value V using coins of denominations D.
// Note : Return 0, if change isn't possible.
// Input Format
// Line 1 : Integer n i.e. total number of denominations
// Line 2 : N integers i.e. n denomination values
// Line 3 : Value V
// Output Format
// Line 1 :  Number of ways i.e. W
// Constraints :
// 1<=n<=10
// 1<=V<=1000
// Sample Input 1 :
// 3
// 1 2 3
// 4
// Sample Output
// 4
// Sample Output Explanation :
// Number of ways are - 4 total i.e. (1,1,1,1), (1,1, 2), (1, 3) and (2, 2).

#include<bits/stdc++.h>
using namespace std;

int find_ways(int denominations[], int numDenominations, int value, int ** arr){
    if(numDenominations == 0){
        return 0;
    }
    if(value < 0){
        return 0;
    }
    if(value == 0){
        return 1;
    }
    if(arr[value][numDenominations]!=-1){
        return arr[value][numDenominations];
    }
    int output = find_ways(denominations, numDenominations, value - denominations[0], arr) + find_ways(denominations + 1, numDenominations - 1, value, arr);
    arr[value][numDenominations] = output;
    return output;
}

int countWaysToMakeChange(int denominations[], int numDenominations, int value){

    /*  Don't write main().
    *  Don't read input, it is passed as function argument.
    *  Return output and don't print it.
    *  Taking input and printing output is handled automatically.
    */

    int ** arr = new int*[value+1];
    for (int i = 0; i < value+1; i++)
    {
        arr[i] = new int[numDenominations+1];
    }
    for (int i = 0; i < value+1; i++)
    {
        for (int j = 0; j < numDenominations+1; j++)
        {
            arr[i][j]=-1;
        }
    }
    int output = find_ways(denominations, numDenominations, value, arr);
    for (int i = 0; i < value+1; i++)
    {
        delete [] arr[i];
    }
    delete [] arr;
    return output;
}

int main(){
    int n;
    cin>>n;
    int * den = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>den[i];
    }
    int value;
    cin>>value;
    cout<<countWaysToMakeChange(den, n, value)<<endl;
    delete [] den;
    return 0;
}