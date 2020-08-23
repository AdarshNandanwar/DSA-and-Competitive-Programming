// https://www.interviewbit.com/problems/xor-ing-the-subarrays/

int Solution::solve(vector<int> &A) {
    int res = 0, n = A.size();
    // if (leftCount+1)*(rightCount+1) is odd
    //    ^^^ = number of subarrays in which this element will appear
    for(int i = 0; i<n; i++) if((((i+1)%2)*((n-i)%2))%2) res ^= A[i];
    return res;
}
