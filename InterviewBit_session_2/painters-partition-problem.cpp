// https://www.interviewbit.com/problems/painters-partition-problem/

bool is_valid(long long A, long long B, vector<int> &C, long long time){
    long long n = C.size(), remaining = time;
    for(long long i = 0; i<n; i++){
        if(B*C[i] > remaining){
            A--;
            if(A == 0) return false;
            remaining = time;
            if(B*C[i] > remaining) return false;
        }
        remaining -= (B*C[i]);
    }
    return true;
}

int Solution::paint(int A, int B, vector<int> &C) {
    // FT first T
    long long hi = 0;
    for(auto i:C) hi += ((long long)B*i);
    long long lo = 0, mid;
    while(lo<hi){
        mid = lo+(hi-lo)/2;
        if(is_valid(A, B, C, mid)){
            hi = mid;
        } else {
            lo = mid+1;
        }
    }
    return lo%10000003;
}
