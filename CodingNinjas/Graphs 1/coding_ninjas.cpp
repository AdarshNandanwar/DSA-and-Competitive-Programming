// Coding Ninjas
// Send Feedback
// Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .
// There is a path from any cell to all its neighbouring cells. A neighbour may share an edge or a corner.
// Input Format :
// Line 1 : Two space separated integers N  and M, where N is number of rows and M is number of columns in the matrix.
// Next N lines : N rows of the matrix. First line of these N line will contain 0th row of matrix, second line will contain 1st row and so on
// Assume input to be 0-indexed based
// Output Format :
// Return 1 if there is a path which makes the sentence “CODINGNINJA” else return 0.
// Constraints :
// 1 <= N <= 100
// 1 <= M <= 100
// Sample Input :
// 2 11
// CXDXNXNXNXA
// XOXIXGXIXJX
// Sample Output :
// 1

#include<bits/stdc++.h>
using namespace std;

bool helper(char ** Graph, int I, int J, int N, int M, string str, int ** visited){
    if(str.length() == 0){
        return true;
    }
    int istart = max(0, I-1), iend = min(N-1, I+1), jstart = max(0, J-1), jend = min(M-1, J+1);
    for (int i = istart; i <= iend; i++)
    {
        for (int j = jstart; j <= jend; j++)
        {
            if(!(i==I && j==J) && (Graph[i][j] == str[0]) && !visited[i][j]){

                visited[i][j] = 1;
                int ans = helper(Graph, i, j, N, M, str.substr(1), visited);
                if(ans){
                    return true;
                }
                visited[i][j] = 0;
            }
        }
        
    }
    return false;
}

int solve(char ** Graph,int N, int M)
{
	// Write your code here.
    int ** visited = new int*[N];
    for (int i = 0; i < N; i++)
    {
        visited[i] = new int[M]();
    }
    
    string str = "CODINGNINJA";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if(Graph[i][j] == 'C'){
                bool ans = helper(Graph, i, j, N, M, str.substr(1), visited);
                if(ans){
                    return 1;
                }
            }
        }
        
    }
    return 0;
}

int main(){
    int n, m;
    cin>>n>>m;
    char ** Graph = new char*[n];
    for (int i = 0; i < n; i++)
    {
        Graph[i] = new char[m];
        cin>>Graph[i];
    }
    int ans = solve(Graph, n, m);
    cout<<ans<<endl;
    for (int i = 0; i < n; i++)
    {
        delete [] Graph[i];
    }
    delete [] Graph;
    return 0;
}