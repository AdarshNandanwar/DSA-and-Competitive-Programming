// https://www.interviewbit.com/problems/grid-unique-paths/

int Solution::uniquePaths(int A, int B) {
    if(A == 0 or B == 0) return 0;
    if(A == 1 or B == 1) return 1;
    A--; B--;
    long long res = 1;
    for(int i = A+B; i>max(A, B); i--) res *= i;
    for(int i = min(A, B); i>=1; i--) res /= i;
    return res;
}