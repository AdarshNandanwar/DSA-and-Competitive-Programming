// https://www.interviewbit.com/problems/flip/

// Method 1 (Kadane's Algorithm):

vector<int> Solution::flip(string A) {
    vector<int> res;
    int max_sum = 0, cur_sum = 0, index = -1;
    for(int i = 0; i<A.length(); i++){
        if(A[i] == '0'){
            cur_sum++;
        } else {
            cur_sum--;
        }
        if(cur_sum < 0){
            cur_sum = 0;
            index = i;
        }
        if(cur_sum > max_sum){
            max_sum = cur_sum;
            res = {index+1+1, i+1};      // one based indexing
        }
    }
    return res;
}

// Method 2 (Cumulative Difference):

vector<int> Solution::flip(string A) {
    unordered_map<int, int> m;
    vector<int> res;
    int ones = 0, zeros = 0, max_diff = 0;
    int max_extra_ones = 0, index = -1;
    for(int i = 0; i<A.length(); i++){
        if(A[i] == '1') ones++;
        else zeros++;
        if(zeros-ones+max_extra_ones > max_diff){
            max_diff = zeros-ones+max_extra_ones;
            res = {index+1+1, i+1};
        }
        if(ones-zeros > max_extra_ones){
            max_extra_ones = ones-zeros;
            index = i;
        }
    }
    return res;
}