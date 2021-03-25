// https://www.interviewbit.com/problems/allocate-books/

bool isValid(vector<int> &A, int mid, int B){
    int n = A.size(), count = 1, cur = 0;
    for(int i = 0; i<n; i++){
        if(A[i] > mid) return false;
        cur += A[i];
        if(cur > mid){
            cur = A[i];
            count++;
        }
        if(count > B) return false;
    }
    return true;
}

int Solution::books(vector<int> &A, int B) {
    if(A.size() < B) return -1;
    int sum = 0;
    for(auto i:A) sum += i;
    int lo = *max_element(A.begin(), A.end()), hi = sum, mid;
    // FFFTTT
    // First True
    while(lo<hi){
        mid = lo + (hi-lo)/2;
        if(isValid(A, mid, B)){
            hi = mid;
        } else {
            lo = mid+1;
        }
    }
    if(isValid(A, lo, B)){
        return lo;
    } else {
        return -1;
    }
}
