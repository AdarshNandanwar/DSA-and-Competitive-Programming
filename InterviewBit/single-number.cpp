// https://www.interviewbit.com/problems/single-number/

int Solution::singleNumber(const vector<int> &A) {
    int res = 0;
    for(auto i:A) res = (res^i);
    return res;
}
