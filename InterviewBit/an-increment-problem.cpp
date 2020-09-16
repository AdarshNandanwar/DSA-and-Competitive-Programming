// https://www.interviewbit.com/problems/an-increment-problem/

// Method 1 (Heap, Hash Table, O(nlogn)):

vector<int> Solution::solve(vector<int> &A) {
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> m;
    vector<int> res;
    for(int i = 0; i<A.size(); i++){
        if(m.count(A[i])){
            int ind = m[A[i]].top();
            m[A[i]].pop();
            if(m[A[i]].empty()) m.erase(A[i]);
            res[ind]++;
            m[res[ind]].push(ind);
        }
        res.push_back(A[i]);
        m[A[i]].push(i);
    }
    return res;
}
