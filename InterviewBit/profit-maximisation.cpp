// https://www.interviewbit.com/problems/profit-maximisation/

// Method 1 (Max Heap, O(nlogn)):

int Solution::solve(vector<int> &A, int B) {
    int res = 0;
    priority_queue<int, vector<int>> pq;
    for(auto i:A) pq.push(i);
    while(B--){
        if(pq.empty()) return res;
        int cur = pq.top();
        pq.pop();
        res += cur;
        if(cur) pq.push(cur-1);
    }
    return res;
}
