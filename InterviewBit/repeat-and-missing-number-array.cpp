// https://www.interviewbit.com/problems/repeat-and-missing-number-array/

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long sum = 0, n = A.size(), curDivisor = 1, curSub = 1;
    double prod = 1;
    
    for(auto i:A){
        sum += i;
        while(sum >= curSub and curSub<=n){
            sum -= curSub;
            curSub++;
        }
        prod *= i;
        while(prod>=curDivisor and curDivisor<=n){
            prod /= curDivisor;
            curDivisor++;
        }
    }
    while(curSub<=n){
        sum -= curSub;
        curSub++;
    }
    while(curDivisor<=n){
        prod /= curDivisor;
        curDivisor++;
    }
    
    double a = (sum*prod)/(prod-1), b = a-sum;
    cout<<a<<" "<<b<<endl;
    return {(int)a, (int)b};
    
}
