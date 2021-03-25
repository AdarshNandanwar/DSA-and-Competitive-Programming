// https://www.interviewbit.com/problems/kth-smallest-element-in-the-array/

int Solution::kthsmallest(const vector<int> &A, int B) {
    int n = A.size();
    if(n == 0) return 0;
    priority_queue<int, vector<int>> pq;
    for(int i = 0; i<n; i++){
        pq.push(A[i]);
        if(i>=B){
            pq.pop();
        }
    }
    return pq.top();
}
