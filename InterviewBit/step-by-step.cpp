// https://www.interviewbit.com/problems/step-by-step/

// Method 1 (Math):

int Solution::solve(int A) {
    if(A == 0) return 0;
    A = abs(A);
    int i = 1, sum;
    while((i*(i+1)/2) < A) i++;
    sum = (i*(i+1))/2;
    if(sum == A) return i;
    if((sum-A)%2){
        sum += i+1;
        return (sum-A)%2 ? i+2 : i+1;
    } else {
        return i;
    }
}
