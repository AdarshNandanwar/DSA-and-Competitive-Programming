// https://www.interviewbit.com/problems/woodcutting-made-easy/

// Method 1 (Binary Search, O(nlogn)):

bool isValid(vector<int> &A, int x, int B){
    for(auto i:A){
        B -= max(0, i-x);
        if(B<=0) return 1;
    }
    return 0;
}

int Solution::solve(vector<int> &A, int B) {
    int lo = 0, hi = *max_element(A.begin(), A.end()), mid, n = A.size();
    // TF first T
    while(lo<hi){
        mid = lo + (hi-lo+1)/2;
        if(isValid(A, mid, B)){
            lo = mid;
        } else {
            hi = mid-1;
        }
    }
    return lo;
}
