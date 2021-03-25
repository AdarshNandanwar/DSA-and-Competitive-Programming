// https://www.interviewbit.com/problems/longest-increasing-subsequence/

// Method 1 (Tails, O(nlogn)):

int Solution::lis(const vector<int> &A) {
    vector<int> tails;
    for(int i = 0; i<A.size(); i++){
        int lb = lower_bound(tails.begin(), tails.end(), A[i])-tails.begin();
        if(lb == tails.size()) tails.push_back(A[i]);
        else tails[lb] = A[i];
    }
    return tails.size();
}

// Method 2 (DP, O(n2)):

int Solution::lis(const vector<int> &A) {
    int n = A.size();
    vector<int> dp(n, 1);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<i; j++) if(A[i]>A[j]) dp[i] = max(dp[i], dp[j]+1);
    }
    return *max_element(dp.begin(), dp.end());
}
