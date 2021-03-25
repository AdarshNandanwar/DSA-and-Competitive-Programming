// https://www.interviewbit.com/problems/max-non-negative-subarray/

vector<int> Solution::maxset(vector<int> &A) {
    long long curSum = 0, st = 0, end = 0, maxSt = 0, maxEnd = -1, n = A.size(), maxSum = -1;
    for(int i = 0; i<n; i++){
        if(A[i] < 0){ 
            curSum = 0;
            st = i+1;
            end = i+1;
            continue;
        }
        curSum += A[i];
        end = i;
        if(maxSum < curSum){
            maxSum = curSum;
            maxSt = st;
            maxEnd = end;
        } else if(maxSum == curSum and end-st > maxEnd-maxSt){
            maxSt = st;
            maxEnd = end;
        }
    }
    return vector<int>(A.begin()+maxSt, A.begin()+maxEnd+1);
}
