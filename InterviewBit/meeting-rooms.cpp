// https://www.interviewbit.com/problems/meeting-rooms/

// Method 1 (Greedy, Heap, O(nlong)):

int Solution::solve(vector<vector<int>> &A) {
    sort(A.begin(), A.end());
    int res = 0;
    // min ending time
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i<A.size(); i++){
        if(pq.empty()){
            pq.push(A[i][1]);
        } else {
            if(pq.top()>A[i][0]){
                pq.push(A[i][1]);
            } else {
                pq.pop();
                pq.push(A[i][1]);
            }
        }
        res = max(res, (int)pq.size());
    }
    return res;
}
