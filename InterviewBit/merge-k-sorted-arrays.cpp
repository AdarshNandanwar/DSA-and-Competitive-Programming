// https://www.interviewbit.com/problems/merge-k-sorted-arrays/

//  Method 1 (Min Heap, O(n*k*log(k))):

vector<int> Solution::solve(vector<vector<int> > &A) {
    int k = A.size();
    vector<int> res;
    if(k == 0) return res;
    int n = A[0].size();
    if(n == 0) return res;
    // {val, {vector no., index}}
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    for(int i = 0; i<k; i++) pq.push({A[i][0], {i, 0}});
    
    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        res.push_back(cur.first);
        if(cur.second.second+1 < n) pq.push({A[cur.second.first][cur.second.second+1], {cur.second.first, cur.second.second+1}});
    }
    return res;
}
