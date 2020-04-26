// Connecting Dots
// Send Feedback
// Gary has a board of size NxM. Each cell in the board is a coloured dot. There exist only 26 colours denoted by uppercase Latin characters (i.e. A,B,...,Z). Now Gary is getting bore and wants to play a game. The key of this game is to find a cycle that contain dots of same colour. Formally, we call a sequence of dots d1, d2, ..., dk a cycle if and only if it meets the following condition:
// 1. These k dots are different: if i ≠ j then di is different from dj.
// 2. k is at least 4.
// 3. All dots belong to the same colour.
// 4. For all 1 ≤ i ≤ k - 1: di and di + 1 are adjacent. Also, dk and d1 should also be adjacent. Cells x and y are called adjacent if they share an edge.
// Since Gary is colour blind, he wants your help. Your task is to determine if there exists a cycle on the board.
// Assume input to be 0-indexed based.
// Input Format :
// Line 1 : Two integers N and M, the number of rows and columns of the board
// Next N lines : a string consisting of M characters, expressing colors of dots in each line. Each character is an uppercase Latin letter.
// Output Format :
// Return 1 if there is a cycle else return 0
// Constraints :
// 2 ≤ N, M ≤ 50
// Sample Input :
// 3 4
// AAAA
// ABCA
// AAAA
// Sample Output :
// 1

#include<bits/stdc++.h>
using namespace std;

bool helper(char ** board, int n, int m, int i, int j, char letter, int ** visited){
    int count = 0;
    if(i>0 && visited[i-1][j] && board[i-1][j] == letter){
        count++;
    }
    if(i<n-1 && visited[i+1][j] && board[i+1][j] == letter){
        count++;
    }
    if(j>0 && visited[i][j-1] && board[i][j-1] == letter){
        count++;
    }
    if(j<m-1 && visited[i][j+1] && board[i][j+1] == letter){
        count++;
    }
    
    if(count>1){
        return true;
    }
    
    bool ans;
    if(i>0 && !visited[i-1][j] && board[i-1][j] == letter){
        visited[i-1][j] = 1;
        ans = helper(board, n, m, i-1, j, letter, visited);
        if(ans){
            return true;
        }
    }
    if(i<n-1 && !visited[i+1][j] && board[i+1][j] == letter){
        visited[i+1][j] = 1;
        ans = helper(board, n, m, i+1, j, letter, visited);
        if(ans){
            return true;
        }
    }
    if(j>0 && !visited[i][j-1] && board[i][j-1] == letter){
        visited[i][j-1] = 1;
        ans = helper(board, n, m, i, j-1, letter, visited);
        if(ans){
            return true;
        }
    }
    if(j<m-1 && !visited[i][j+1] && board[i][j+1] == letter){
        visited[i][j+1] = 1;
        ans = helper(board, n, m, i, j+1, letter, visited);
        if(ans){
            return true;
        }
    }
    return false;
}

int solve(char ** board,int n, int m)
{
    bool ans;
    int ** visited = new int*[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = new int[m]();
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(!visited[i][j]){
                visited[i][j] = 1;
                ans = helper(board, n, m , i, j, board[i][j], visited);
                if(ans){
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main(){
    int n,m;
    cin>>n>>m;
    char ** board = new char*[n];
    for (int i = 0; i < n; i++)
    {
        board[i] = new char[m];
        cin>>board[i];
    }
    int ans = 0;
    ans = solve(board, n, m);
    cout<<ans<<endl;
    delete [] board;
    return 0;
}