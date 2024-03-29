// https://www.interviewbit.com/problems/min-xor-value/

int Solution::findMinXor(vector<int> &A) {
    sort(A.begin(), A.end());
    int res = INT_MAX;
    for(int i = 0; i<A.size()-1; i++) res = min(res, A[i]^A[i+1]);
    return res;
}
