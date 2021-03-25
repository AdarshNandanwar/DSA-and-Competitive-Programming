// https://www.interviewbit.com/problems/min-jumps-array/

int Solution::jump(vector<int> &A) {
    int n = A.size();
    if(n <= 1) return 0;
    
    int count = 0, pos = 0, curRange = 0, nextRange = 0;
    
    while(1){
        while(pos <= curRange){
            nextRange = max(nextRange, A[pos]+pos);
            pos++;
        }
        
        if(nextRange >= n-1) return count+1;
        
        if(curRange == nextRange) return -1;
        curRange = nextRange;
        count++;
    }
    return count;
}
