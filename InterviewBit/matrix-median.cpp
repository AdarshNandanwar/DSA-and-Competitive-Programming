// https://www.interviewbit.com/problems/matrix-median/

// Method 1 (Binary Search, O(n*log(m)*log(n*m)) time, O(n*m) space):

int Solution::findMedian(vector<vector<int> > &A) {
    int n = A.size();
    if(n == 0) return 0;
    int m = A[0].size();
    vector<int> flat;
    for(auto i:A) for(auto j:i) flat.push_back(j);
    sort(flat.begin(), flat.end());
    int nf = flat.size();
    // sum(lb(mid)) < nf/2+1
    // TF, last true
    int lo = 0, hi = nf-1, mid, sum = 0;
    while(lo<hi){
        mid = lo+(hi-lo+1)/2;
        sum = 0;
        for(int i = 0; i<n; i++) sum += (lower_bound(A[i].begin(), A[i].end(), flat[mid])-A[i].begin());
        if(sum < nf/2+1){
            lo = mid;
        } else {
            hi = mid-1;
        }
    }
    return flat[lo];
}
