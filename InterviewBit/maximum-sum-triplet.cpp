// https://www.interviewbit.com/problems/maximum-sum-triplet/

// Method 1 (Hash Table, Binary Search, O(nlogn)):

int Solution::solve(vector<int> &A) {
    int n = A.size(), res = 0, temp;
    vector<int> suffixMax(A.begin(), A.end());
    for(int i = n-2; i>=0; i--) suffixMax[i] = max(suffixMax[i], suffixMax[i+1]);
    set<int> prefixEle;
    prefixEle.insert(A[0]);
    for(int j = 1; j<n-1; j++){
        auto itr = prefixEle.lower_bound(A[j]);
        temp = -1;
        if(itr != prefixEle.begin()) temp = *prev(itr);
        prefixEle.insert(A[j]);
        if(temp == -1 or A[j] >= suffixMax[j+1]) continue;
        res = max(res, temp+A[j]+suffixMax[j+1]);
    }
    return res;
}
