// https://www.interviewbit.com/problems/painters-partition-problem/

bool isValid(int availableWorkers, int B, vector<int> & C, long time){
    long curTime = 0, n = C.size();
    for(int i = 0; i<n; i++){
        if(curTime + ((long)B*C[i]) <= time){
            curTime += ((long)B*C[i]);
        } else {
            availableWorkers--;
            if(availableWorkers == 0) return 0;
            curTime = ((long)B*C[i]);
            if(curTime > time) return 0;
        }
    }
    return 1;
}

int Solution::paint(int A, int B, vector<int> &C) {
    long sum = 0;
    for(auto i:C) sum += i;
    
    //  fffttt first true
    long lo = *max_element(C.begin(), C.end()), hi = sum*B, mid;
    
    while(lo<hi){
        mid = lo+(hi-lo)/2;
        if(isValid(A, B, C, mid)){
            hi = mid;
        } else {
            lo = mid+1;
        }
    }
    if(isValid(A, B, C, lo)){
        return lo%10000003;
    } else {
        return -1;
    }
}
