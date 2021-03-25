// https://www.interviewbit.com/problems/all-unique-permutations/

void helper(vector<int> & A, int index, vector<int> & cur, vector<vector<int>> & res, unordered_map<int, int> & freq){
    if(index == A.size()){
        res.push_back(cur);
        return;
    }
    
    for(int i = 0; i<A.size(); i++){
        if(freq[A[i]] and (i == 0 or A[i]!=A[i-1])){
            cur.push_back(A[i]);
            freq[A[i]]--;
            helper(A, index+1, cur, res, freq);
            freq[A[i]]++;
            cur.pop_back();
        }
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    
    sort(A.begin(), A.end());
    vector<vector<int>> res;
    vector<int> cur;
    unordered_map<int, int> freq;
    for(auto i:A) freq[i]++;
    
    helper(A, 0, cur, res, freq);
    return res;
    
}
