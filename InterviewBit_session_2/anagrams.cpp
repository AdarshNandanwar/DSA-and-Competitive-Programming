// https://www.interviewbit.com/problems/anagrams/

vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    unordered_map<string, vector<int>> m;
    for(int i = 0; i<A.size(); i++){
        string key = A[i];
        sort(key.begin(), key.end());
        m[key].push_back(i+1);
    }
    vector<vector<int> > res;
    for(auto & i:m) res.push_back(i.second);
    return res;
}
