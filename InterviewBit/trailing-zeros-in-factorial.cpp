// https://www.interviewbit.com/problems/trailing-zeros-in-factorial/

// Method 1 (Math, O(logn)):

int Solution::trailingZeroes(int A) {
    int res=  0;
    for(long i = 5; i<=A; i*=5) res += A/i;
    return res;
}