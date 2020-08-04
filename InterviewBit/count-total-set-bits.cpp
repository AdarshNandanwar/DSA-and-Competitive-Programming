// https://www.interviewbit.com/problems/count-total-set-bits/

// Method 1 (Bit Recursion, O(32)):

#define MOD 1000000007

void helper(int & n, int index, int & setBitsInLeft, int & res){
    if(index < 0) {
        // number of bits in A
        res = (res + setBitsInLeft)%MOD;
        return;
    }
    if(n&(1ll<<index)){
        // if bit at index is 0
        if(index-1 >= 0) res = (res + ((index%MOD)*((1ll<<(index-1))%MOD))%MOD)%MOD;
        res = (res + (setBitsInLeft*((1ll<<index)%MOD))%MOD)%MOD;
        setBitsInLeft++;
    }
    // if bit at index is 1
    helper(n, index-1, setBitsInLeft, res);
}

int Solution::solve(int A) {
    int res = 0;
    int len = 0, num = A, setBitsInLeft = 0;
    while(num){
        len++;
        num = num>>1;
    }
    // index here is reverse i.e. from the right
    helper(A, len-1, setBitsInLeft, res);
    return res;
}

// Method 2 (Brute Force, O(32*n)):

#define MOD 1000000007

int Solution::solve(int A) {
    int res = 0;
    for(int i = 1; i<=A; i++){
        int j = i;
        while(j){
            res = (res + (j&1))%MOD;
            j = j>>1;
        }
    }
    return res%MOD;
}