// https://www.interviewbit.com/problems/maximum-sum-combinations/

struct Cmp{
    bool operator()(const pair<int, pair<int, int>> & a, const pair<int, pair<int, int>> & b) const {
        return a.first+a.second.first < b.first+b.second.first;
    }
};

vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    int n = A.size();
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, Cmp> pq;
    for(auto i:A) pq.push({i, {B[0], 0}});
    vector<int> res;
    while(C--){
        auto cur = pq.top();
        pq.pop();
        res.push_back(cur.first+cur.second.first);
        int nextIndex = cur.second.second+1;
        if(nextIndex<n) pq.push({cur.first, {B[nextIndex], nextIndex}});
    }
    return res;
}
