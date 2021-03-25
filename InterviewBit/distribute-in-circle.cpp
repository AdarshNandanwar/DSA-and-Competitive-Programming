// https://www.interviewbit.com/problems/distribute-in-circle/

int Solution::solve(int A, int B, int C) {
    return (C-1+A-1)%B+1;
}
