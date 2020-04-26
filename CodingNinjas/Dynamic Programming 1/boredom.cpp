// Boredom
// Send Feedback
// Gary is bored and wants to play an interesting but tough game . So he figured out a new board game called "destroy the neighbours" . In this game there are N integers on a board. In one move, he can pick any integer x from the board and then all the integers with value x+1 or x-1 gets destroyed .This move will give him x points.
// He plays the game until the board becomes empty . But as he want show this game to his friend Steven, he wants to learn techniques to maximise the points to show off . Can you help Gary in finding out the maximum points he receive grab from the game ?
// Input Format :
// Line 1 : Integer N 
// Line 2 : A list of N integers
// Output Format :
// Maximum points Gary can recieve from the Game setup
// Constraints :
// 1<=N<=10^5
// 1<=A[i]<=1000
// Sample Input :
// 2
// 1 2
// Sample Output :
// 2

#include<bits/stdc++.h>
using namespace std;

int calculate_points(int * elements, int size,  int * frequency, int * dp){
    if(size == 0){
        return 0;
    }
    if(size == 1){
        return elements[0]*frequency[elements[0]];
    }
    if(dp[size] != -1){
        return dp[size];
    }
    
    int option1, option2;
    if(elements[size-2] + 1 != elements[size-1]){
        option1 = elements[size-1]*frequency[elements[size-1]] + calculate_points(elements, size-1, frequency, dp);
    }else{
        option1 = elements[size-1]*frequency[elements[size-1]] + calculate_points(elements, size-2, frequency, dp);
    }
    option2 = calculate_points(elements, size-1, frequency, dp);
    int output = max(option1, option2);
    dp[size] = output;
    return output;
}

int solve(int n,vector<int>A){
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
    int frequency[100000];
    for(int i=0; i<100000; i++){
        frequency[i] = 0;
    }
    vector<int>::iterator it;
    int size = 0;
    for(it = A.begin(); it != A.end(); it++){
        frequency[*it]++;
        if(frequency[*it] == 1){
            size++;
        }
    }
    int k=0;
    int * elements = new int[size];
    for(int i=0; i<100000; i++){
        if(frequency[i]!=0){
            elements[k]=i;
            k++;
        }
    }
    int * dp = new int[size+1];
    for(int i = 0; i < size+1; i++){
        dp[i] = -1;
    }
    sort(elements, elements + size);
    int points = calculate_points(elements, size, frequency, dp);
    delete [] elements;
    delete [] dp;
    return points;
}