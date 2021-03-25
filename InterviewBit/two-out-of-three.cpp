// https://www.interviewbit.com/problems/two-out-of-three/

// Method 1 (bool array of range for a, b, c and then see if ele in atleast 2, O(range))

// Method 2 (Hash Table, Sorting, O(nlogn)):

vector<int> Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    unordered_set<int> sa(A.begin(), A.end()), sb(B.begin(), B.end()), mix;
    for(auto i:sb) if(sa.count(i)) mix.insert(i);
    for(auto i:C) if(sa.count(i) or sb.count(i)) mix.insert(i);
    vector<int> ans(mix.begin(), mix.end());;
    sort(ans.begin(), ans.end());
    return ans;
}
