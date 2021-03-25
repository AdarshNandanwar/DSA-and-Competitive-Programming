// https://www.interviewbit.com/problems/array-3-pointers/

int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int pa = 0, pb = 0, pc = 0, na = A.size(), nb = B.size(), nc = C.size(), res = INT_MAX;
    while(pa<na and pb<nb and pc<nc){
        res = min(res, max(abs(A[pa] - B[pb]), max(abs(B[pb] - C[pc]), abs(C[pc] - A[pa]))));
        if(A[pa] < B[pb]){
            if(A[pa] < C[pc]){
                pa++;
            } else {
                pc++;
            }
        } else {
            if(B[pb] < C[pc]){
                pb++;
            } else {
                pc++;
            }
        }
    }
    return res;
}