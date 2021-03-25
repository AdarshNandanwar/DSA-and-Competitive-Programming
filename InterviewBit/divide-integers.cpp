// https://www.interviewbit.com/problems/divide-integers/

int Solution::divide(int A, int B) {
    if(A == INT_MIN and B == -1) return INT_MAX;
    if(B == 1) return A;
    if(B == -1) return -A;
    if(B == 0) return INT_MAX;
    int q = 0;
    bool isPos = (A>=0 == B>=0);
    long a = abs((long)A), b = abs((long)B);
    while(a >= b){
        int p = 0;
        // p: (1<<p) is the max number of times (power of 2) B can be removed from A
        while(a >= (b<<(p+1))) p++;
        q += (1<<p);
        a -= (b<<p);
    }
    return isPos ? q : -q;
}
