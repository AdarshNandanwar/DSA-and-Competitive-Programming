// https://www.interviewbit.com/problems/different-bits-sum-pairwise/

#define MOD 1000000007

int Solution::cntBits(vector<int> &A) {
    vector<long> bitCount(32, 0);
    long res = 0, n = A.size();
    for(auto i:A){
        for(int j = 0; j<32 and i; j++, i = i>>1) bitCount[j] += (i&1);
    }
    for(int i = 0; i<32; i++) res = (res+((bitCount[i]*(n-bitCount[i]))%MOD))%MOD;
    return (2*res)%MOD;
}
