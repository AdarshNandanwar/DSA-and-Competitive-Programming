// https://www.interviewbit.com/problems/trailing-zeros-in-factorial/

// Method 1 (Math):

int Solution::trailingZeroes(int A) {
    long res = 0, p = 5;
    while(p<=A){
        res += A/p;
        p *= 5;
    }
    return res;
}
