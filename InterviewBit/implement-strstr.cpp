// https://www.interviewbit.com/problems/implement-strstr/

// Method 1 (KMP Algorithm, O(n+m)):

void calculateLps(const string & p, vector<int> & lps){
    int n = p.length();
    if(n <= 1) return;
    lps[0] = 0;
    int i = 1, j = lps[i-1];
    
    while(i<n){
        if(p[i] == p[j]){
            lps[i] = j+1;
            i++;
            j = lps[i-1];
        } else {
            if(j != 0){
                j = lps[j-1];
            } else {
                lps[i] = 0;
                i++;
                j = lps[i-1];
            }
        }
    }
}

int Solution::strStr(const string s, const string p) {
    int n = s.length(), m = p.length();
    
    // lps[i] = longest proper prefix which is also a proper suffix of [0..i]
    vector<int> lps(m, 0);
    calculateLps(p, lps);
    
    int p1 = 0, p2 = 0;
    while(p1<n){
        if(s[p1] == p[p2]){
            p1++;
            p2++;
        } else {
            if(p2 == 0){
                p1++;
            } else {
                p2 = lps[p2-1];
            }
        }
        if(p2 == m) return p1-m;
    }
    return -1;
}

// Method 2 (O(n*m)):

int Solution::strStr(const string A, const string B) {
    int na = A.length(), nb = B.length(), j;
    for(int i = 0; i+nb-1<na; i++){
        for(j = 0; j<nb; j++) if(A[i+j] != B[j]) break;
        if(j == nb) return i;
    }
    return -1;
}
