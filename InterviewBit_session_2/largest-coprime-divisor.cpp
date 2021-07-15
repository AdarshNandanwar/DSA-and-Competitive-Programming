// https://www.interviewbit.com/problems/largest-coprime-divisor/

// Method 1 (__gcd):

int Solution::cpFact(int A, int B) {
    if(__gcd(A, B) == 1) return A;
    return cpFact(A/__gcd(A, B), B);
}
