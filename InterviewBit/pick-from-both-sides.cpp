// https://www.interviewbit.com/problems/pick-from-both-sides/

// Method 1 (Array, O(B) time, O(1) space):

int Solution::solve(vector<int> &A, int B) {
    int n = A.size(), res = 0, cur;
    for(int i = 0; i<B; i++) res += A[i];
    cur = res;
    for(int i = 0; i<B; i++){
        cur = cur-A[B-1-i]+A[n-1-i];
        res = max(res, cur);
    }
    return res;
}

// Method 2 (DP, O(n) time, O(n) space):

int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    vector<int> prefixSum;
    prefixSum.push_back(0);
    // prefixSum[i] = sum[0..i) i.e. first i terms
    for(auto i:A) prefixSum.push_back(prefixSum.back()+i);
    int res = INT_MIN;
    for(int i = 0; i<=B; i++){
        res = max(res, prefixSum[i]+prefixSum[n]-prefixSum[n-(B-i)]);
    }
    return res;
}
