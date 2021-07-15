// https://www.interviewbit.com/problems/maximum-unsorted-subarray/

// Method 1 (O(n));

vector<int> Solution::subUnsort(vector<int> &A) {
    int n = A.size();
    int max_till_now = INT_MIN, min_misplaced = INT_MAX;
    for(int i = 0; i<n; i++){
        if(A[i] < max_till_now){
            min_misplaced = min(min_misplaced, A[i]);
        }
        max_till_now = max(max_till_now, A[i]);
    }
    if(min_misplaced == INT_MAX) return {-1};
    int min_till_now = INT_MAX, max_misplaced = INT_MIN;
    for(int i = n-1; i>=0; i--){
        if(A[i] > min_till_now){
            max_misplaced = max(max_misplaced, A[i]);
        }
        min_till_now = min(min_till_now, A[i]);
    }
    int l = 0, r = n-1;
    while(l<n and A[l] <= min_misplaced) l++;
    while(r>=0 and A[r] >= max_misplaced) r--;
    return {l, r};
}

// Method 2 (Cheating, O(nlogn)):

vector<int> Solution::subUnsort(vector<int> &A) {
    vector<int> v(A);
    sort(v.begin(), v.end());
    int l = 0, r = A.size()-1;
    while(l<A.size()){
        if(v[l] != A[l]) break;
        l++;
    }
    if(l == A.size()) return {-1};
    while(r>=0){
        if(v[r] != A[r]) break;
        r--;
    }
    return {l, r};
}
