// https://www.interviewbit.com/problems/k-largest-elements/

vector<int> Solution::solve(vector<int> &A, int B) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto i:A){
        pq.push(i);
        if(pq.size() > B) pq.pop();
    }
    vector<int> res;
    while(!pq.empty()){
        res.push_back(pq.top());
        pq.pop();
    }
    return res;
}
