// https://www.interviewbit.com/problems/n-max-pair-combinations/

vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    int n = A.size();
    vector<int> ans;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    // {A[i]+B[j], {i, j} where i = index in A, j = index in B
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>> pq;
    for(int i = 0; i<n; i++) pq.push({A[i]+B[n-1], {i, n-1}});
    while(n--){
        auto cur = pq.top();
        pq.pop();
        ans.push_back(cur.first);
        if(cur.second.second-1 >= 0) pq.push({A[cur.second.first]+B[cur.second.second-1], {cur.second.first, cur.second.second-1}});
    }
    return ans;
}
