// https://www.interviewbit.com/problems/bulbs/

// Method 1 (Greedy):

int Solution::bulbs(vector<int> &A) {
    int count = 0;
    for(auto i:A) if((i+count)%2 == 0) count++;
    return count;
}
