// https://www.interviewbit.com/problems/noble-integer/

// Method 1 (O(nlogn) time, O(1) space):

int Solution::solve(vector<int> &A) {
    int n = A.size();
    if(n == 0) return -1;
    sort(A.begin(), A.end());
    for(int i = 0; i<n; i++) if(i+1<n and A[i] != A[i+1] and n-i-1 == A[i]) return 1;
    if(A[n-1] == 0) return 1;
    return -1;
}
