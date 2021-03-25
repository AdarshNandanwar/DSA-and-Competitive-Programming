// https://www.interviewbit.com/problems/single-number-ii/

int Solution::singleNumber(const vector<int> &A) {
    vector<long> bit(32, 0);
    for(auto i:A){
        for(int j = 0; j<32; j++){
            bit[j] += ((bool)(i&(1<<j)));
        }
    }
    int res = 0;
    for(int i = 0; i<32; i++){
        res += (((bool)(bit[i]%3))<<i);
    }
    return res;
}
