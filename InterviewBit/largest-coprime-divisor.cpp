// https://www.interviewbit.com/problems/largest-coprime-divisor/

// Method 1 (Math, gcd, O(log(n)*log(n)):

int Solution::cpFact(int A, int B) {
    while(__gcd(A, B) != 1) A /= __gcd(A, B);
    return A;
}

// Method 2 (MLE, O(A)):

int Solution::cpFact(int A, int B) {
    vector<int> primeFactors;
    vector<bool> isPrime(A+1, 1);
    isPrime[0] = isPrime[1] = 0;
    
    for(int i = 2; i<=A; i++){
        if(isPrime[i]){
            if(A%i == 0) primeFactors.push_back(i);
            for(int j = i*i; j<=A; j+=i){
                isPrime[j] = 0;
            }
        }
    }
    
    int res = 1;
    
    for(auto i:primeFactors){
        if(__gcd(i, B) == 1){
            int a = A;
            while(a%i == 0){
                res *= i;
                a/=i;
            }
        }
    }
    
    return res;
}
