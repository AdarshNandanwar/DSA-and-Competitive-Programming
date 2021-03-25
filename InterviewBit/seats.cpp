// https://www.interviewbit.com/problems/seats/

// Method 1 (Greedy, O(n)):

#define MOD 10000003
typedef long long int ll;

int Solution::seats(string A) {
    ll n = A.length(), leftCount, rightCount, count = 0, ind, left = 0, right = 0;
    if(n == 0) return 0;
    
    for(ll i = 0; i<n; i++) if(A[i] == 'x') count++;
    
    if(count == 0) return 0;
    
    ll median = (count-1)/2, c = 0;
    // ind = index of lower median
    for(ind = 0; ind<n; ind++){
        if(A[ind] == 'x') c++;
        if(c > median) break;
    }
    
    leftCount = median+1, rightCount = count-leftCount;
    
    // left = sum of occupied indices in [0..median]
    // right = sum of occupied indices in [median+1..n-1]
    
    for(ll i = ind; i>=0; i--) left += (A[i] == 'x' ? i : 0);
    for(ll i = ind+1; i<n; i++) right += (A[i] == 'x' ? i : 0);
    
    // sum of difference between ideal indices and current indices
    
    ll r1 = ind*leftCount - ((leftCount-1)*leftCount)/2 - left;
    ll r2 = right - (ind+1)*rightCount - ((rightCount-1)*rightCount)/2;
    
    return (r1+r2)%MOD;
}

// Method 2 (DP, Failing for large test cases, O(n)):

#define MOD 10000003
typedef long long int ll;

int Solution::seats(string A) {
    ll n = A.length(), res = INT_MAX, leftCount = 0, rightCount, count = 0, r1, r2;
    if(n == 0) return 0;
    // left[i] = sum of occupied indices in [0..i]
    // right[i] = sum of occupied indices in [i..n-1]
    vector<ll> left(n, 0), right(n, 0);
    for(ll i = 0; i<n; i++) if(A[i] == 'x') count++;
    for(ll i = 1; i<n; i++) left[i] = left[i-1]+(A[i] == 'x' ? i : 0);
    if(A[n-1] == 'x') right[n-1] = n-1;
    for(ll i = n-2; i>=0; i--) right[i] = right[i+1]+(A[i] == 'x' ? i : 0);
    for(ll i = 0; i<n; i++){
        if(A[i] == 'x') leftCount++;
        rightCount = count-leftCount;
        r1 = r2 = 0;
        r1 = (i*leftCount - ((leftCount-1)*leftCount)/2 - left[i]);
        if(i+1<n) r2 = (right[i+1] - (i+1)*rightCount - ((rightCount-1)*rightCount)/2);
        res = min(res, r1+r2);
    }
    return res%MOD;
}