// https://www.interviewbit.com/problems/valid-bst-from-preorder/

bool helper(vector<int> & A, int st, int end){
    if(st >= end) return 1;
    int mid = st+1;
    while(mid<=end and A[mid] <= A[st]) mid++;
    for(int i = mid; i<=end; i++) if(A[i]<=A[st]) return 0;
    return helper(A, st+1, mid-1) and helper(A, mid, end);
}

int Solution::solve(vector<int> &A) {
    return helper(A, 0, A.size()-1);
}
