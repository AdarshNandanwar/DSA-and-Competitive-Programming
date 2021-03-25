// https://www.interviewbit.com/problems/maximum-ones-after-modification/

// Method 1 (2 Pointers, O(n)):

int Solution::solve(vector<int> &A, int B) {
    int n = A.size(), res = 0, p1 = 0, p2 = 0, zeros = 0;
    // [p1, p2);
    while(p2<n){
        if(A[p2] == 0) zeros++;
        p2++;
        while(zeros>B){
            if(A[p1] == 0) zeros--;
            p1++;
        }
        res = max(res, p2-p1);
    }
    return res;
}
