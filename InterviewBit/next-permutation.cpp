// https://www.interviewbit.com/problems/next-permutation/

vector<int> Solution::nextPermutation(vector<int> &A) {
    int n = A.size(), i, j;
    for(i = n-2; i>=0; i--) if(A[i] < A[i+1]) break;
    if(i < 0){
        sort(A.begin(), A.end());
        return A;
    }
    for(j = i; j+1<n; j++) if(A[j+1]<=A[i]) break;
    swap(A[i], A[j]);
    sort(A.begin()+i+1, A.end());
    return A;
}
