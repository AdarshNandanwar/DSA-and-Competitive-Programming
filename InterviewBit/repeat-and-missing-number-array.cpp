// https://www.interviewbit.com/problems/repeat-and-missing-number-array/

// Method 1 (Maths, O(n) time, O(1) space):

typedef long long int ll;
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    ll a_minus_b = 0, a2_minus_b2 = 0, a_plus_b = 0, n = A.size();     //A-B, A^2-B^2, A+B
    for(ll i = 0; i<n; i++){
        a_minus_b += (A[i]-(i+1));
        a2_minus_b2 += ((ll)A[i]*A[i]-(i+1)*(i+1));
    }
    a_plus_b = a2_minus_b2/a_minus_b;
    return {(a_plus_b+a_minus_b)/2, (a_plus_b-a_minus_b)/2};
}

// Method 2:

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
