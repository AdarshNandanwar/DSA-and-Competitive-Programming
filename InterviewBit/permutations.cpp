// https://www.interviewbit.com/problems/permutations/

void helper(vector<int> &A, vector<bool> & visited, vector<int>& cur, vector<vector<int> >& res){
    if(cur.size() >= A.size()){
        res.push_back(cur);
        return;
    }
    
    for(int i = 0; i<A.size(); i++){
        if(visited[i]) continue;
        visited[i] = true;
        cur.push_back(A[i]);
        helper(A, visited, cur, res);
        cur.pop_back();
        visited[i] = false;
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<int> cur;
    vector<bool> visited(A.size());
    vector<vector<int> > res;
    helper(A, visited, cur, res);
    return res;
}
