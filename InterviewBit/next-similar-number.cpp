// https://www.interviewbit.com/problems/next-similar-number/

string Solution::solve(string A) {
    int n = A.length(), i, j;
    for(i = n-2; i>=0 and A[i]>=A[i+1]; i--){}
    if(i < 0) return "-1";
    for(j = i+1; j<n and A[j]>A[i]; j++){}
    swap(A[i], A[j-1]);
    reverse(A.begin()+i+1, A.end());
    return A;
}
