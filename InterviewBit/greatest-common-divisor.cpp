// https://www.interviewbit.com/problems/greatest-common-divisor/

int Solution::gcd(int A, int B) {
    return B == 0 ? A : gcd(B, A%B);
}