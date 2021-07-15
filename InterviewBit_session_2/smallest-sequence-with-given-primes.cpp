// https://www.interviewbit.com/problems/smallest-sequence-with-given-primes/

// Method 1 (3 Pointer, Ugly Numbers)

vector<int> Solution::solve(int A, int B, int C, int D) {
    vector<int> ans(1, 1);
    vector<int> p(3, 0);
    while(ans.size() <= D){
        int m = min(A*ans[p[0]], min(B*ans[p[1]], C*ans[p[2]]));
        if(m == A*ans[p[0]]) p[0]++;
        if(m == B*ans[p[1]]) p[1]++;
        if(m == C*ans[p[2]]) p[2]++;
        ans.push_back(m);
    }
    return vector<int>(ans.begin()+1, ans.end());
}
