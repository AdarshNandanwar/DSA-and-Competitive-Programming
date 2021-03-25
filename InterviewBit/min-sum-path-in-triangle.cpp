// https://www.interviewbit.com/problems/min-sum-path-in-triangle/

// Method 1 (DP, O(n2)):

int Solution::minimumTotal(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int n = A.size();
    if(n == 0) return 0;
    // dp[i][j] = min path sum from A[i][j] to bottom;
    for(int i = n-2; i>=0; i--){
        for(int j = 0; j<i+1; j++){
            A[i][j] += min(A[i+1][j], A[i+1][j+1]);
        }
    }
    return A[0][0];
}
