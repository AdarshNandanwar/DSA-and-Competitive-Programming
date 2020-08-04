// https://www.interviewbit.com/problems/first-missing-integer/

int Solution::firstMissingPositive(vector<int> &A) {
    int n = A.size();
    for(int i = 0; i<n; i++){
        while(1<=A[i] and A[i]<=n and A[i] != A[A[i]-1]) swap(A[i], A[A[i]-1]);
    }
    for(int i = 0; i<n; i++) if(A[i] != i+1) return i+1;
    return n+1;
}
