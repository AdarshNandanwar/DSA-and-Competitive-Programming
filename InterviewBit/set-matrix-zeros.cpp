// https://www.interviewbit.com/problems/set-matrix-zeros/

void Solution::setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int n = A.size();
    if(n == 0) return;
    int m = A[0].size();
    vector<bool> row(n, true), col(m, true);
    for(int  i =0; i<n; i++){
        for(int j  =0 ; j<m; j++){
            if(A[i][j] == 0) row[i] = col[j] = false;
        }
    }
    for(int  i =0; i<n; i++){
        for(int j  =0 ; j<m; j++){
            if(row[i] == false or col[j] == false) A[i][j] = 0;
        }
    }
}
