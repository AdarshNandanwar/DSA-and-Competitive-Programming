// https://www.interviewbit.com/problems/array-3-pointers/

int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int na = A.size(), nb = B.size(), nc = C.size();
    if(na == 0 or nb == 0 or nc == 0) return 0;
    int res = INT_MAX, cur;
    vector<int> p(3, 0);
    while(p[0]<na and p[1]<nb and p[2]<nc){
        res = min(res, max(abs(A[p[0]]-B[p[1]]), max(abs(A[p[0]]-C[p[2]]), abs(B[p[1]]-C[p[2]]))));
        cur = min(A[p[0]], min(B[p[1]], C[p[2]]));
        if(A[p[0]] == cur) p[0]++;
        if(B[p[1]] == cur) p[1]++;
        if(C[p[2]] == cur) p[2]++;
    }
    return res;
}
