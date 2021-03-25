// https://www.interviewbit.com/problems/magician-and-chocolates/

// Method 1 (Max Heap, O(nlogn)):

int Solution::nchoc(int A, vector<int> &B) {
    priority_queue<int, vector<int>> pq;
    for(auto i:B) pq.push(i);
    long res = 0;
    while(A-- and !pq.empty()){
        int cur = pq.top();
        res = (res + cur)%1000000007;
        pq.pop();
        if(cur/2 > 0) pq.push(cur/2);
    }
    return res;
}
