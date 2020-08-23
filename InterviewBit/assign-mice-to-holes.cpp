// https://www.interviewbit.com/problems/assign-mice-to-holes/

// Method 1 (Sort, Greedy, O(nlongn)):

int Solution::mice(vector<int> &A, vector<int> &B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int res = 0;
    for(int i = 0; i<A.size(); i++) res = max(res, abs(A[i]-B[i]));
    return res;
}
