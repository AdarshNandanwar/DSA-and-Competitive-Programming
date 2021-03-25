// https://www.interviewbit.com/problems/rotate-matrix/

void Solution::rotate(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int n = A.size(), oi, oj, ni, nj, temp;
    for(int i = 0; i<=(n-1)/2; i++){
        for(int j = 0; j<n/2; j++){
            oi = n-j-1; oj = i;
            temp = A[oi][oj];
            for(int k =0; k<4; k++){
                ni = oj; nj = n-oi-1;
                swap(temp, A[ni][nj]);
                oi = ni; oj = nj;
            }
        }
    }
}
