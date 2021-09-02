// https://www.interviewbit.com/problems/sudoku/

bool helper(vector<vector<char>> &A, int i, int j, vector<vector<bool>> &row, vector<vector<bool>> &col, vector<vector<bool>> &box){
    if(j == 9){
        i++;
        j = 0;
    }
    if(i == 9) return 1;
    if(A[i][j] != '.') return helper(A, i, j+1, row, col, box);
    for(int k = 0; k<9; k++){
        if(!row[i][k] and !col[j][k] and !box[3*(i/3)+j/3][k]){
            A[i][j] = k+'1';
            row[i][k] = col[j][k] = box[3*(i/3)+j/3][k] = 1;
            if(helper(A, i, j+1, row, col, box)) return 1;
            A[i][j] = '.';
            row[i][k] = col[j][k] = box[3*(i/3)+j/3][k] = 0;
        }
    }
    return 0;
}

void Solution::solveSudoku(vector<vector<char>> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<vector<bool>> row(9, vector<bool>(9, 0)), col(9, vector<bool>(9, 0)), box(9, vector<bool>(9, 0));
    for(int i = 0; i<9; i++){
        for(int j = 0; j<9; j++){
            if(A[i][j] != '.'){
                int val = A[i][j]-'1';
                row[i][val] = col[j][val] = box[3*(i/3)+j/3][val] = 1;
            }
        }
    }
    helper(A, 0, 0, row, col, box);
    return;
}
