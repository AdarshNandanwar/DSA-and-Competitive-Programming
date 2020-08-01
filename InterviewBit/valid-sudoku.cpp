// https://www.interviewbit.com/problems/valid-sudoku/

int Solution::isValidSudoku(const vector<string> &A) {
    
    // [col][number]
    vector<vector<bool>> col(9, vector<bool>(9)), row(9, vector<bool>(9)), box(9, vector<bool>(9));
    
    for(int i = 0; i<9; i++){
        for(int j = 0; j<9; j++){
            if(A[i][j] == '.') continue;
            if(col[j][A[i][j]-'1'] or row[i][A[i][j]-'1'] or box[(i/3)*3+j/3][A[i][j]-'1']) return 0;
            col[j][A[i][j]-'1'] = row[i][A[i][j]-'1'] = box[(i/3)*3+j/3][A[i][j]-'1'] = 1;
        }
    }
    return 1;
}
