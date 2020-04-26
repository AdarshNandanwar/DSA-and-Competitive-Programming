// Largest Piece
// Send Feedback
// Its Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . But Gary wants the biggest piece of '1's and no '0's . A piece of cake is defined as a part which consist of only '1's, and all '1's share an edge with eachother on the cake. Given the size of cake N and the cake , can you find the size of the biggest piece of '1's for Gary ?
// Constraints :
// 1<=N<=50
// Input Format :
// Line 1 : An integer N denoting the size of cake 
// Next N lines : N characters denoting the cake
// Output Format :
// Size of the biggest piece of '1's and no '0's
// Sample Input :
// 2
// 11
// 01
// Sample Output :
// 3

#include<bits/stdc++.h>
using namespace std;

int helper(char ** cake, int I, int J, int N, int ** visited){
    int ans = 1, i = I, j = J, flag = 1;
    i = I+1;
    if(i<N && cake[i][j] == '1' && !visited[i][j]){
        visited[i][j] = 1;
        flag = 0;
        ans += helper(cake, i, j, N, visited);
    }
    i = I-1;
    if(i>=0 && cake[i][j] == '1' && !visited[i][j]){
        visited[i][j] = 1;
        flag = 0;
        ans += helper(cake, i, j, N, visited);
    }
    i = I;
    j = J+1;
    if(j<N && cake[i][j] == '1' && !visited[i][j]){
        visited[i][j] = 1;
        flag = 0;
        ans += helper(cake, i, j, N, visited);
    }
    j = J-1;
    if(j>=0 && cake[i][j] == '1' && !visited[i][j]){
        visited[i][j] = 1;
        flag = 0;
        ans += helper(cake, i, j, N, visited);
    }
    if(flag){
        return 1;
    }
    return ans;
}

int solve(int n,char ** cake)
{
	// Write your code here.
    int ans = 0;
    int ** visited = new int*[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = new int[n]();
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(cake[i][j] == '1' && !visited[i][j]){
                visited[i][j] = 1;
                ans = max(ans, helper(cake, i, j, n, visited));
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        delete [] visited[i];
    }
    delete [] visited;
    return ans;
}

int main(){
    int n;
    cin>>n;
    char ** cake = new char*[n];
    for (int i = 0; i < n; i++)
    {
        cake[i] = new char[n];
        cin>>cake[i];
    }
    int ans = solve(n, cake);
    cout<<ans<<endl;
    for (int i = 0; i < n; i++)
    {
        delete [] cake[i];
    }
    delete [] cake;
    return 0;
}