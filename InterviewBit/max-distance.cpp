// https://www.interviewbit.com/problems/max-distance/

int Solution::maximumGap(const vector<int> &A){
    int n = A.size(), res = 0;
    
    vector<pair<int, int>> A_sorted;
    for(int i = 0; i<n; i++) A_sorted.push_back({A[i], i});
    sort(A_sorted.begin(), A_sorted.end());
    
    vector<int> index_in_A_sorted(n);
    for(int i = 0; i<n; i++) index_in_A_sorted[A_sorted[i].second] = i;
    
    // calculating the suffix max in the index part of the A_sorted
    for(int i = n-2; i>=0 ; i--) A_sorted[i].second = max(A_sorted[i].second, A_sorted[i+1].second);
    
    for(int i = 0; i<n and res < n-i-1; i++){
        res = max(res, A_sorted[index_in_A_sorted[i]].second-i);
    }
    return res;
}
