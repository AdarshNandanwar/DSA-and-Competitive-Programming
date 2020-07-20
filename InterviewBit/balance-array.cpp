// https://www.interviewbit.com/problems/balance-array/

int Solution::solve(vector<int> &A) {
    int n  =A.size();
    // inclusive
    vector<int> PrefixEven(n, 0), PrefixOdd(n, 0), SuffixEven(n, 0), SuffixOdd(n, 0);
    
    for(int i = 0; i<n; i++){
        if(i%2 == 0){
            PrefixEven[i] = (i-2>=0 ? PrefixEven[i-2] : 0)+A[i];
            PrefixOdd[i] = (i-1>=0 ? PrefixOdd[i-1] : 0);
        } else {
            PrefixEven[i] = (i-1>=0 ? PrefixEven[i-1] : 0);
            PrefixOdd[i] = (i-2>=0 ? PrefixOdd[i-2] : 0)+A[i];
        }
    }
    for(int i = n-1; i>=0; i--){
        if(i%2 == 0){
            SuffixEven[i] = (i+2<n ? SuffixEven[i+2] : 0)+A[i];
            SuffixOdd[i] = (i+1<n ? SuffixOdd[i+1] : 0);
        } else {
            SuffixEven[i] = (i+1<n ? SuffixEven[i+1] : 0);
            SuffixOdd[i] = (i+2<n ? SuffixOdd[i+2] : 0)+A[i];
        }
    }
    int count = 0;
    for(int i = 0; i<n; i++){
        if(PrefixEven[i]+SuffixOdd[i] == PrefixOdd[i]+SuffixEven[i]) count++;
    }
    return count;
}
