// https://www.interviewbit.com/problems/max-distance/

int Solution::maximumGap(const vector<int> &A) {
    vector<pair<int, int>> v;
    int n = A.size();
    for(int i = 0; i<n; i++){
        v.push_back({A[i], i});
    }
    sort(v.begin(), v.end());
    int res = 0, min_i = INT_MAX;
    for(int i = 0; i<n; i++){
        min_i = min(min_i, v[i].second);
        res = max(res, v[i].second-min_i);
    }
    return res;
}
