// https://www.interviewbit.com/problems/majority-element/

int Solution::majorityElement(const vector<int> &A) {
    int res = INT_MIN, freq = 0;
    for(int i:A){
        if(res == i) freq++;
        else freq--;
        if(freq<=0){
            res = i;
            freq = 1;
        }
    }
    return res;
}
