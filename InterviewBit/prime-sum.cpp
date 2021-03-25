// https://www.interviewbit.com/problems/prime-sum/

vector<int> Solution::primesum(int A) {
    int n = A;
    vector<bool> v(n+1, 1);       // isPrime?
    v[0] = v[1] = 0;
    for(int i = 2; i*i<=n; i++){
        if(v[i]){
            for(int j = 2*i; j<n; j+=i){
                v[j] = 0;
            }
        }
    }
    for(int i = 2; i<n; i++) if(v[i] and v[n-i]) return {i, n-i};
    return {0,0};
}
