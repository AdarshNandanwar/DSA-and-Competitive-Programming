// https://www.interviewbit.com/problems/minimum-characters-required-to-make-a-string-palindromic/

vector<int> getLps(const string & s){
    int n = s.length();
    vector<int> lps(n, 0);
    int i = 1, j = lps[i-1];
    while(i<n){
        if(s[i] == s[j]){
            lps[i] = j+1;
            i++;
            j = lps[i-1];
        } else {
            if(j == 0){
                lps[i] = 0;
                i++;
                j = lps[i-1];
            } else {
                j = lps[j-1];
            }
        }
    }
    return lps;
}

int Solution::solve(string A) {
    int n = A.length();
    string comb = A;
    reverse(A.begin(), A.end());
    comb = comb+A;
    auto lps = getLps(comb);
    return max(0, n-lps[2*n-1]);
}