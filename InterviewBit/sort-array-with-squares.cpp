// https://www.interviewbit.com/problems/sort-array-with-squares/

// Method 1 (Segrigation, O(n)):

vector<int> Solution::solve(vector<int> &A) {
    vector<int> pos, neg, res(A.size());
    for(auto i:A) if(i>=0) pos.push_back(i*i); else neg.push_back(i*i);
    reverse(neg.begin(), neg.end());
    merge(pos.begin(), pos.end(), neg.begin(), neg.end(), res.begin());
    return res;
}

// Method 2 (Sort, O(nlogn)):

vector<int> Solution::solve(vector<int> &A) {
    vector<int> res;
    for(auto i:A) res.push_back(i*i);
    sort(res.begin(), res.end());
    return res;
}
