// https://www.interviewbit.com/problems/4-sum/

// Method 1 (Hash Table):

vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    vector<vector<int> > res;
    long n = A.size();
    sort(A.begin(), A.end());
    unordered_set<long> s;
    unordered_set<string> done;
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            for(int k = j+1; k<n; k++){
                if(s.count(B-A[i]-A[j]-A[k])){
                    string key = to_string(A[i])+"/"+to_string(A[j])+"/"+to_string(A[k]);
                    if(!done.count(key)){
                        res.push_back({B-A[i]-A[j]-A[k], A[i], A[j], A[k]});
                        done.insert(key);
                    }
                }
            }
        }
        s.insert(A[i]);
    }
    sort(res.begin(), res.end());
    return res;
}
