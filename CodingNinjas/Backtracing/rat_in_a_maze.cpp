// Rat In A Maze Problem
// Send Feedback
// You are given a N*N maze with a rat placed at maze[0][0]. Find and print all paths that rat can follow to reach its destination i.e. maze[N-1][N-1]. Rat can move in any direc­tion ( left, right, up and down).
// Value of every cell in the maze can either be 0 or 1. Cells with value 0 are blocked means rat can­not enter into those cells and those with value 1 are open.
// Input Format
// Line 1 : Integer N
// Next N Lines : Each line will contain ith row elements (separated by space)
// Output Format :
// One Line for every possible solution. 
// Every line will have N*N maze elements printed row wise and are separated by space. Only cells that are part of solution path should be 1, rest all cells should be 0.
// Sample Input 1 :
// 3
// 1 0 1
// 1 0 1
// 1 1 1
// Sample Output 1 :
// 1 0 0 1 0 0 1 1 1 
// Sample Output 1 Explanation :
// Only 1 path is possible
// Sample Input 2 :
// 3
// 1 0 1
// 1 1 1
// 1 1 1
// Sample Output 2 :
// 1 0 0 1 1 1 1 1 1 
// 1 0 0 1 0 0 1 1 1 
// 1 0 0 1 1 0 0 1 1 
// 1 0 0 1 1 1 0 0 1 
// Sample Output 2 Explanation :
// 4 paths are possible




#include<bits/stdc++.h>
using namespace std;

void navigator(int maze[][20], int n, int** arr, int x, int y);

void check_and_go(int maze[][20], int n, int** arr, int x, int y){
    if(x>=0 && x<n && y>=0 && y<n && maze[x][y]==1 && arr[x][y]==0){
        arr[x][y]=1;
        navigator(maze, n, arr, x, y);
        arr[x][y]=0;
    }
    return;
}

void navigator(int maze[][20], int n, int** arr, int x, int y){
    if(arr[n-1][n-1] == 1){
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // cout<<arr[i][j]<<" ";
            }
        }
        // cout<<endl;
        return;
    }
    check_and_go(maze, n, arr, x-1, y);
    check_and_go(maze, n, arr, x+1, y);
    check_and_go(maze, n, arr, x, y-1);
    check_and_go(maze, n, arr, x, y+1);
    return;
}

void ratInAMaze(int maze[][20], int n){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Print output as specified in the question
  */
    int ** arr = new int*[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            arr[i][j]=0;
        }
    }
    
    arr[0][0]=1;
    
    navigator(maze, n, arr, 0, 0);

    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}

int main(){
    int n;
    cin>>n;
    int maze[20][20];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>maze[i][j];
        }
    }
    ratInAMaze(maze, n);
    return 0;
}
