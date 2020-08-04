// https://www.interviewbit.com/problems/max-sum-contiguous-subarray/

int Solution::maxSubArray(const vector<int> &A) {
    int sum = 0, res = INT_MIN;
    for(auto i:A){
        sum += i;
        res = max(res, sum);
        if(sum<0) sum = 0;
    }
    return res;
}
