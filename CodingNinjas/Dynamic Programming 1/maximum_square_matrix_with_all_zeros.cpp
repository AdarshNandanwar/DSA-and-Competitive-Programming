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

int findMaxSquareWithAllZeros(int** input, int row, int col){

    int * arr = new int[row];
    
    int max_square_side = 0;

    for (int start = 0; start < col; start++)
    {
        for (int i = 0; i < row; i++)
        {
            arr[i] = 0;
        }
        
        for (int end = start; end < col; end++)
        {
            int max_length = 0,length = 0;
            for (int i = 0; i < row; i++)
            {
                arr[i]+=input[i][end];
                if(arr[i] == 0){
                    length++;
                }else{
                    length = 0;
                }
                max_length = max(max_length, length);
            }       
            max_square_side = max(max_square_side, min(end-start+1, max_length));
        }
        
    }
    delete [] arr;
    return max_square_side;
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