// https://www.interviewbit.com/problems/max-distance/

int Solution::maximumGap(const vector<int> &A) {
    int n = A.size(), res = 0;
    vector<pair<int, int>> A_sorted;
    for(int i = 0; i<n; i++) A_sorted.push_back({A[i], i});
    sort(A_sorted.begin(), A_sorted.end());
    // calculating the suffix max in the index part of the A_sorted
    for(int i = n-2; i>=0 ; i--){
        int right_max = max(A_sorted[i].second, A_sorted[i+1].second);
        res = max(res, right_max-A_sorted[i].second);
        A_sorted[i].second = right_max;
    } 
    return res;
}