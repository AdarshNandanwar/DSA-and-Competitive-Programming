#include<bits/stdc++.h>
using namespace std;

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

void find_number(int board[9][9], int x, int y){
    if(y==9){
        cout<<endl;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    
    if(board[y][x]==0){
        for (int i = 1; i <= 9; i++)
        {
            if(check(board, x, y, i)){
                board[y][x]=i;
                if(x==8){
                    find_number(board, 0, y+1);
                }else{
                    find_number(board, x+1, y);
                }
                board[y][x]=0;
            }
        }    
    }else{
        if(x==8){
            find_number(board, 0, y+1);
        }else{
            find_number(board, x+1, y);
        }
    }
    return;
}

void solve(int board[9][9]){
    find_number(board, 0, 0);
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
    solve(board);
    return 0;
}