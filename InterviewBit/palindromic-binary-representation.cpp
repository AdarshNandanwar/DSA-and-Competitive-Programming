// https://www.interviewbit.com/problems/palindromic-binary-representation/

int helper(int A, int curLen){
    int bucketSize = pow(2, (curLen+1)/2-1);
    if(A >= bucketSize){
        return helper(A-bucketSize, curLen+1);
    } else {
        int res = 1, p1, p2;
        res |= (1<<(curLen-1));
        if(curLen%2){
            // odd
            p1 = p2 = curLen/2;
            while(A){
                res |= ((A&1)<<p1);
                res |= ((A&1)<<p2);
                p1++;
                p2--;
                A = A>>1;
            }
        } else {
            // even
            p1 = curLen/2;
            p2 = curLen/2-1;
            while(A){
                res |= ((A&1)<<p1);
                res |= ((A&1)<<p2);
                p1++;
                p2--;
                A = A>>1;
            }
        }
        return res;
    }
}

int Solution::solve(int A) {
    if(A == 1) return 1;
    // first and last bits are always 1
    // bucketSize is the number of ways of palindromic bits in [st+1, end-1]
    // curLen is the current guessed length of the palindromic bits
    return helper(A-1, 1);
}
