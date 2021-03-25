// https://www.interviewbit.com/problems/min-steps-in-infinite-grid/

int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    int res= 0, n = A.size();
    for(int i = 1; i<n; i++){
        res += max(abs(A[i]-A[i-1]), abs(B[i]-B[i-1]));
    }
    return res;
}
