// https://www.interviewbit.com/problems/counting-subarrays/

// Method 1 (2 pointers, O(n)):

int Solution::solve(vector<int> &A, int B) {
    int n = A.size(), p1 = 0, p2 = 0, curSum = 0, res = 0;;
    while(p2<n){
        curSum += A[p2++];
        while(curSum>=B) curSum -= A[p1++];
        res += (p2-p1);
    }
    return res;
}
