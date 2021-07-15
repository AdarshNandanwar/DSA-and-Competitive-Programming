// https://www.interviewbit.com/problems/length-of-longest-subsequence/

int Solution::longestSubsequenceLength(const vector<int> &A) {
    int n = A.size(), res = 0;
    vector<int> inc(n, 1), dec(n, 1);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<i; j++){
            if(A[i] > A[j]) inc[i] = max(inc[i], 1+inc[j]);
        }
    }
    for(int i = n-1; i>=0; i--){
        for(int j = n-1; j>i; j--){
            if(A[i] > A[j]) dec[i] = max(dec[i], 1+dec[j]);
        }
        res = max(res, inc[i]+dec[i]-1);
    }
    return res;
}
