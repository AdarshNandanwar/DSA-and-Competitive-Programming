// https://www.interviewbit.com/problems/length-of-longest-subsequence/

// Method 1 (DP, O(n)):

int Solution::longestSubsequenceLength(const vector<int> &A) {
    int n = A.size(), res = 0;
    vector<int> lis(n, 1), lds(n, 1);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<i; j++){
            if(A[i] > A[j]) lis[i] = max(lis[i], 1+lis[j]);
        }
    }
    for(int i = n-1; i>=0; i--){
        for(int j = n-1; j>i; j--){
            if(A[i] > A[j]) lds[i] = max(lds[i], 1+lds[j]);
        }
        res = max(res, lds[i]+lis[i]-1);
    }
    return res;
}
