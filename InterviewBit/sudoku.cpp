// https://www.interviewbit.com/problems/sudoku/

// Method 1 (Backtracking):

void helper(vector<vector<char>> &A, int r, int c, vector<vector<bool>> & row, vector<vector<bool>> & col, vector<vector<bool>> & block, bool & done){
    if(r == 9) done = 1;
    if(done) return;
    if(A[r][c] != '.'){
        if(c == 8) helper(A, r+1, 0, row, col, block, done);
        else helper(A, r, c+1, row, col, block, done);
    } else {
        for(int i = 0; i<9; i++){
            if(row[r][i] or col[c][i] or block[3*(r/3)+c/3][i] or A[r][c] != '.') continue;
            row[r][i] = col[c][i] = block[3*(r/3)+c/3][i] = 1;
            A[r][c] = '1'+i;
            if(c == 8) helper(A, r+1, 0, row, col, block, done);
            else helper(A, r, c+1, row, col, block, done);
            if(done) return;
            A[r][c] = '.';
            row[r][i] = col[c][i] = block[3*(r/3)+c/3][i] = 0;
        }
    }
}

void Solution::solveSudoku(vector<vector<char> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    bool done = 0;
    vector<vector<bool>> row(9, vector<bool>(9, 0)), col(9, vector<bool>(9, 0)), block(9, vector<bool>(9, 0));
    for(int r = 0; r<9; r++){
        for(int c = 0; c<9; c++){
            if(A[r][c] != '.') row[r][A[r][c]-'1'] = col[c][A[r][c]-'1'] = block[3*(r/3)+c/3][A[r][c]-'1'] = 1;
        }
    }
    helper(A, 0, 0,row, col, block, done);
}