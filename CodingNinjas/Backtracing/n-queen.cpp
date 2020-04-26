// N-Queen Problem
// Send Feedback
// You are given N, and for a given N x N chessboard, find a way to place N queens such that no queen can attack any other queen on the chess board. A queen can be killed when it lies in the same row, or same column, or the same diagonal of any of the other queens. You have to print all such configurations.
// Input Format :
// Line 1 : Integer N
// Output Format :
// One Line for every board configuration. 
// Every line will have N*N board elements printed row wise and are separated by space
// Note : Don't print anything if there isn't any valid configuration.
// Constraints :
// 1<=N<=10
// Sample Input 1:
// 4
// Sample Output 1 :
// 0 1 0 0 0 0 0 1 1 0 0 0 0 0 1 0 
// 0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0 


#include<bits/stdc++.h>
using namespace std;

void printAnswer(stack<int> st){
    int n = st.size();
    while(!st.empty()){
        for (int i = 0; i < n; i++)
        {
            if(i==st.top()){
                cout<<1<<" ";
            }else{
                cout<<0<<" ";
            }
        }
        st.pop();
    }
    cout<<endl;
}

// Just a fun function to print the board with all possible valid queen placements

// void printBoard(stack<int> st){
//     int n = st.size();
//     while(!st.empty()){
//         cout<<"|";
//         for (int i = 0; i < n; i++)
//         {
//             if(i==st.top()){
//                 cout<<"Q"<<"|";
//             }else{
//                 cout<<" "<<"|";
//             }
//         }
//         cout<<endl;
//         st.pop();
//     }
//     cout<<endl;
// }

bool check(int row, int col, stack<int> st){
    int pos=row-1;
    while(!st.empty()){
        st.top();
        if((row-pos)==abs(col-st.top()) || col==st.top()){
            return false;
        }
        st.pop();
        pos--;
    }
    return true;
}

void recurseQueen(int n, stack<int> & st){
    if(st.size()==n){
        printAnswer(st);        // replace with printBoard(st); to see the board
        return;
    }

    int row = st.size();
    for (int i = 0; i < n; i++)
    {
        if(check(row, i, st)){
            st.push(i);
            recurseQueen(n, st);
            st.pop();
        }
    }
    return;
}

void placeNQueens(int n){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Print output as specified in the question
  */
    stack<int> st;
    recurseQueen(n, st);
}


int main(){
    int n;
    cin>>n;
    placeNQueens(n);
    return 0;
}