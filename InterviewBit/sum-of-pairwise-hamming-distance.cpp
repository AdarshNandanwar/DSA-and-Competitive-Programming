// https://www.interviewbit.com/problems/sum-of-pairwise-hamming-distance/

#define MOD 1000000007

int Solution::hammingDistance(const vector<int> &A) {
    int n = A.size();
    vector<int> freq(32, 0);
    for(auto a:A){
        for(int i = 0; i<32; i++){
            freq[i] += ((bool)(a&(1<<i)));
        }
    }
    int res = 0;
    for(auto a:A){
        for(int i = 0; i<32; i++){
            if(a&(1<<i)){
                res = (res + (n-freq[i]))%MOD;
            } else {
                res = (res + freq[i])%MOD;
            }
        }
    }
    return res;
}
