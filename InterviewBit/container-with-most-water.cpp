// https://www.interviewbit.com/problems/container-with-most-water/

int Solution::maxArea(vector<int> &A) {
    int n = A.size();
    int p1 = 0, p2 = n-1, ans = 0;
    while(p1<p2){
        ans = max(ans, min(A[p2], A[p1])*(p2-p1));
        if(A[p1] < A[p2]) p1++;
        else p2--;
    }
    return ans;
}
