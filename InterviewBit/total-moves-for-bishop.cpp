// https://www.interviewbit.com/problems/total-moves-for-bishop/

int Solution::solve(int A, int B) {
    int res = 0;
    res += min(A-1, B-1);
    res += min(A-1, 8-B);
    res += min(8-A, B-1);
    res += min(8-A, 8-B);
    return res;
}
