// https://www.interviewbit.com/problems/maximum-absolute-difference/

// Method 1 (Math, Absolute Properties, Cases, O(n2)):

int Solution::maxArr(vector<int> &A) {
    int n = A.size(), res = 0;
    if(n == 0) return 0;
    int minMinus = INT_MAX, maxMinus = INT_MIN, minPlus = INT_MAX, maxPlus = INT_MIN;
    for(int i = 0; i<n; i++){
        minMinus = min(minMinus, A[i]-i);
        maxMinus = max(maxMinus, A[i]-i);
        minPlus = min(minPlus, A[i]+i);
        maxPlus = max(maxPlus, A[i]+i);
        res = max(maxMinus - minMinus, maxPlus - minPlus);
    }
    return res;
}

// Method 2 (Brute Force, O(n2)):

int Solution::maxArr(vector<int> &A) {
    int n = A.size(), res = 0;
    if(n == 0) return 0;
    int maxElement = A[0], minElement = A[0];
    for(int i = 0; i<n; i++){
        minElement = min(minElement, A[i]);
        maxElement = max(maxElement, A[i]);
    }
    for(int i = 0; i<n; i++){
        for(int j = n-1; j>=0 and res < maxElement-minElement+abs(j-i); j--){
            res = max(res, abs(i-j)+abs(A[i]-A[j]));
        }
    }
    return res;
}
