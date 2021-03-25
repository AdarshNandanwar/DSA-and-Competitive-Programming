// https://www.interviewbit.com/problems/subarray-with-equal-occurences/

// Method 1 (Hash Table, O(n)):

int Solution::solve(vector<int> &A, int B, int C) {
    // m[i] = no of subarrays with diff in num of B and C = i
    unordered_map<int, int> m;
    m[0] = 1;
    int cur = 0, res = 0;
    for(auto i:A){
        if(i == B) cur++;
        else if(i == C) cur--;
        if(m.count(cur)) res += m[cur];
        m[cur]++;
    }
    return res;
}
