// https://www.interviewbit.com/problems/jump-game-array/

int Solution::canJump(vector<int> &A) {
    int n = A.size();
    if(n<=1) return 1;
    int pos = 0, curRange = 0, nextRange = 0;
    while(1){
        while(pos<=curRange){
            nextRange = max(nextRange, pos+A[pos]);
            pos++;
        }
        if(nextRange >= n) return 1;
        if(nextRange == curRange) return 0;
        curRange = nextRange;
    }
    return 0;
}
