// https://www.interviewbit.com/problems/perfect-peak-of-array/

int Solution::perfectPeak(vector<int> &A) {
    int n = A.size();
    vector<int> prefixMax(n, INT_MIN), suffixMin(n, INT_MIN);
    for(int i = 0; i<n; i++){
        if(i == 0) prefixMax[i] = A[i];
        else prefixMax[i] = max(prefixMax[i-1], A[i]);
    }
    for(int i = n-1; i>=0; i--){
        if(i == n-1) suffixMin[i] = A[i];
        else suffixMin[i] = min(suffixMin[i+1], A[i]);
        if(i>0 and i<n-1 and prefixMax[i-1] < A[i] and A[i] < suffixMin[i+1]) return 1;
    }
    return 0;
}
