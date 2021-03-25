// https://www.interviewbit.com/problems/trailing-zeroes/

int Solution::solve(int A) {
    int res = 0;
    while(A and (A&1) == 0){
        res++;
        A = A>>1;
    } 
    return res;
}

// OR

int Solution::solve(int A) {
    int res = 0;
    while(A and A%2 == 0){
        res++;
        A /= 2;
    } 
    return res;
}
