// https://www.interviewbit.com/problems/anagrams/

vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    unordered_map<string, vector<int>> m;
    vector<vector<int> >res;
    int n = A.size();
    for(int i = 0; i<n ;i++){
        string s = A[i];
        sort(s.begin(), s.end());
        m[s].push_back(i+1);
    }
    for(auto [i,j]:m){
        res.push_back(j);
    }
    return res;
}
