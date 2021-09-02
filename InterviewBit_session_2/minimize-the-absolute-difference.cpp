// https://www.interviewbit.com/problems/minimize-the-absolute-difference/

int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    vector<int> v(3, 0), n(3, 0);
    n[0] = A.size(); n[1] = B.size(); n[2] = C.size();
    int res = INT_MAX, min_val, max_val;
    while(v[0]<n[0] and v[1]<n[1] and v[2]<n[2]){
        min_val = min(A[v[0]], min(B[v[1]], C[v[2]]));
        max_val = max(A[v[0]], max(B[v[1]], C[v[2]]));
        res = min(res,  max_val-min_val);
        if(A[v[0]] == min_val) v[0]++;
        if(B[v[1]] == min_val) v[1]++;
        if(C[v[2]] == min_val) v[2]++;
    }
    return res;
}
