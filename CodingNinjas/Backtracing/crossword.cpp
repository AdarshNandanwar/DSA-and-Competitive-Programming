// Crossword Problem
// Send Feedback
// CodingNinjas has provided a crossword of 10*10 grid. The grid contains '+' or '-' as its cell values. Now, you are also provided with word list which needs to placed accurately in the grid. Cells marked with '-' are to be filled with word list.
// For example: The following is an example for the input crossword grid and the word list.
// +-++++++++
// +-++-+++++
// +-------++
// +-++-+++++
// +-++-+++++
// +-++-+++++
// ++++-+++++
// ++++-+++++
// ++++++++++
// ----------
// CALIFORNIA;NIGERIA;CANADA;TELAVIV
// Output for the given input should be:
// +C++++++++
// +A++T+++++
// +NIGERIA++
// +A++L+++++
// +D++A+++++
// +A++V+++++
// ++++I+++++
// ++++V+++++
// ++++++++++
// CALIFORNIA
// Note: We have provided such test cases that there is only one solution for the given input.
// Input format:
// The first 10 lines of input contains crossword. Each of 10 lines have a character array of size 10. Input characters are either '+' or '-'.
// Next line of input contains the word list, in which each word is separated by ';'. 
// Output format:
// Print the crossword grid, after placing the words of word list in '-' cells.  
// Sample Test Cases:
// Sample Input 1:
// +-++++++++
// +-++-+++++
// +-------++
// +-++-+++++
// +-++-+++++
// +-++-+++++
// ++++-+++++
// ++++-+++++
// ++++++++++
// ----------
// CALIFORNIA;NIGERIA;CANADA;TELAVIV
// Sample Output 1:
// +C++++++++
// +A++T+++++
// +NIGERIA++
// +A++L+++++
// +D++A+++++
// +A++V+++++
// ++++I+++++
// ++++V+++++
// ++++++++++
// CALIFORNIA

#include<bits/stdc++.h>
using namespace std;

#define N 10

void solve(string * grid, vector<string> word_list, int x, int y);
void solve_across(string * grid, vector<string> word_list, int x, int y);
void solve_down(string * grid, vector<string> word_list, int x, int y);


int across_length(string * grid, int x, int y){
    int count =0;
    while(x<N && grid[y][x] != '+'){
        count++;
        x++;
    }
    return count;
}

int down_length(string * grid, int x, int y){
    int count =0;
    while(y<N && grid[y][x] != '+'){
        count++;
        y++;
    }
    return count;
}

bool is_valid_across(string * grid, int x, int y){
    if(x == 0){
        return true;
    }else if(grid[y][x-1] == '+'){
        return true;
    }
    return false;
}

bool is_valid_down(string * grid, int x, int y){
    if(y == 0){
        return true;
    }else if(grid[y-1][x] == '+'){
        return true;
    }
    return false;
}

void put_word_across(string * grid, vector<string> word_list, int i, int x, int y){

    bool flag = true;
    string word = word_list[i];
    vector<int> pos;
    for (int i = 0; i < word.length(); i++)
    {
        if(grid[y][x+i] == '-'){
            grid[y][x+i] = word[i];
        }else if(grid[y][x+i] == word[i]){
            pos.push_back(x+i);
            continue;
        }else{
            pos.push_back(x+i);
            flag = false;
            continue;
        }
    }

    if(flag){

        solve_down(grid, word_list, x, y);
    }

    for (int i = 0; i < word.length(); i++)
    {
        int f = 0;
        for (int j = 0; j < pos.size(); j++)
        {
            if(x+i == pos[j]){
                f = 1;
            }
        }
        if(f){
            continue;
        }else{
            grid[y][x+i] = '-';
        }
    }

    return;
}

void put_word_down(string * grid, vector<string> word_list, int i, int x, int y){

    bool flag = true;
    string word = word_list[i];
    vector<int> pos;
    for (int i = 0; i < word.length(); i++)
    {
        if(grid[y+i][x] == '-'){
            grid[y+i][x] = word[i];
        }else if(grid[y+i][x] == word[i]){
            pos.push_back(y+i);
            continue;
        }else{
            pos.push_back(y+i);
            flag = false;
            continue;
        }
    }

    if(flag){
        if(x == N-1){
            solve_across(grid, word_list, 0, y+1);
        }else{
            solve_across(grid, word_list, x+1, y);
        }
    }

    for (int i = 0; i < word.length(); i++)
    {
        int f = 0;
        for (int j = 0; j < pos.size(); j++)
        {
            if(y+i == pos[j]){
                f = 1;
            }
        }
        if(f){
            continue;
        }else{
            grid[y+i][x] = '-';
        }
    }
    return;
}



void solve_across(string * grid, vector<string> word_list, int x, int y){
    
    if( y == N){
        for (int i = 0; i < N; i++)
        {
            cout<<grid[i]<<endl;
        }
        return;
    }

    if(grid[y][x] == '+'){
        if(x == N-1){
            solve_across(grid, word_list, 0, y+1);
        }else{
            solve_across(grid, word_list, x+1, y);
        }
    }else{
        int a_length = across_length(grid, x, y);
        bool check_across = is_valid_across(grid, x, y);

        if(a_length != 1 && check_across){
            for (int i = 0; i < word_list.size(); i++)
            {
                if(word_list[i].length() == a_length){
                    put_word_across(grid, word_list, i, x, y);
                }
            } 
        }else{
            solve_down(grid, word_list, x, y);
        }   
    }
    return;
}

void solve_down(string * grid, vector<string> word_list, int x, int y){

    if(y == N){
        for (int i = 0; i < N; i++)
        {
            cout<<grid[i]<<endl;
        }
        return;
    }

    int d_length = down_length(grid, x, y);
    bool check_down = is_valid_down(grid, x, y);
    if(d_length != 1 && check_down){
        for (int i = 0; i < word_list.size(); i++)
        {
            if(word_list[i].length() == d_length){
                put_word_down(grid, word_list, i, x, y);
            }
        }
    }else{
        if(x == N-1){
            solve_across(grid, word_list, 0, y+1);
        }else{
            solve_across(grid, word_list, x+1, y);
        }
    }     
    return;
}

int main(){

    string * grid = new  string[N];
    
    for (int i = 0; i < N; i++)
    {
        cin>>grid[i];
    }
    
    string words;
    vector<string> word_list;
    cin>>words;
    int start = 0, count = 0;
    for (int i = 0; i < words.length(); i++)
    {
        count++;
        if(words[i] == ';'){
            word_list.push_back(words.substr(start, count-1));
            start = i+1;
            count = 0;
        }
    }
    word_list.push_back(words.substr(start, count));

    solve_across(grid, word_list, 0, 0);

    delete[] grid;
    return 0;
}