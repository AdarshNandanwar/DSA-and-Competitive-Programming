// https://www.interviewbit.com/problems/sliding-window-maximum/

vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    int n = A.size();
    if(n == 0) return {};
    if(n <= B) return {*max_element(A.begin(), A.end())};
    vector<int> res;
    // index
    deque<int> dq;
    for(int i = 0; i<n; i++){
        while(!dq.empty() and dq.front() <= i-B) dq.pop_front();
        while(!dq.empty() and A[dq.back()]<= A[i]) dq.pop_back();
        dq.push_back(i);
        if(i>=B-1) res.push_back(A[dq.front()]);
    }
    return res;
}
