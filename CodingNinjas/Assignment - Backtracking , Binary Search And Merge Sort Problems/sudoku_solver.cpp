#include<bits/stdc++.h>
using namespace std;

void print_board(int board[][9]){
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool find_next_zero(int board[][9], int & x, int & y){
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if(board[i][j]==0){
                x=j;
                y=i;
                return true; 
            }
        }
    }
    return false;
}

bool check(int board[9][9], int x, int y, int num){
    for (int i = 0; i < 9; i++)
    {
        if(board[i][x]==num){
            return false;
        }
    }
    for (int i = 0; i < 9; i++)
    {
        if(board[y][i]==num){
            return false;
        }
    }

    for (int i = (y-(y%3)); i < (y-(y%3))+3; i++)
    {
        for (int j = (x-(x%3)); j < (x-(x%3))+3; j++)
        {
            if(board[i][j]==num){
                return false;
            }
        }
    }
    
    return true;
}

void find_number(int board[9][9], int x, int y, bool & solvable){
    if(!solvable){
        for (int i = 1; i <= 9; i++)
        {
            if(check(board, x, y, i)){
                board[y][x]=i;
                int new_x=x, new_y=y;
                if(find_next_zero(board, new_x, new_y)){
                    find_number(board, new_x, new_y, solvable);
                }else{
                    // print_board(board);
                    solvable = true;
                }
                board[y][x]=0;
            }
        }    
    }
    return;
}

bool sudokuSolver(int board[][9]){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Don't print output and return output as specified in the question
  */
    bool solvable = false;
    int new_x=0, new_y=0;
    if(find_next_zero(board, new_x, new_y)){
        find_number(board, new_x, new_y, solvable);
    }else{
        return true;
    }
    return solvable;
}

int main(){
    int board[9][9];
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin>>board[i][j];
        }   
    }
    cout<<sudokuSolver(board);
    return 0;
}