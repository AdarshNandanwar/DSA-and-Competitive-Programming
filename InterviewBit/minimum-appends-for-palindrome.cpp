// https://www.interviewbit.com/problems/minimum-appends-for-palindrome/

// Mehtod 1 (KMP LPS, O(n)):

int getLPS(string s){
    int n = s.length();
    vector<int> lps(n);
    lps[0] = 0;
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
    return lps[n-1];
}

int Solution::solve(string A) {
    string s = A;
    reverse(s.begin(), s.end());
    s += A;
    return max(0, (int)A.length()-getLPS(s));
}
