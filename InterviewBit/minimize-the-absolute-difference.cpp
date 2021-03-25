// https://www.interviewbit.com/problems/minimize-the-absolute-difference/

// Method 1 (3 pointers, O(n)):

int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    int p1 = 0, p2 = 0, p3 = 0, n1 = A.size(), n2 = B.size(), n3 = C.size(), res = INT_MAX;
    while(p1<n1 and p2<n2 and p3<n3){
        res = min(res, abs(max(A[p1], max(B[p2], C[p3]))-min(A[p1], min(B[p2], C[p3]))));
        if(A[p1] < B[p2]){
            if(A[p1] < C[p3]){
                p1++;
            } else {
                p3++;
            }
        } else {
            if(B[p2] < C[p3]){
                p2++;
            } else {
                p3++;
            }
        }
    }
    return res;
}
