// https://www.interviewbit.com/problems/implement-strstr/

vector<int> get_lps(const string &B){
    int n = B.length();
    vector<int> lps(n, 0);
    int i = 1, j = lps[0];
    while(i<n){
        if(B[j] == B[i]){
            lps[i++] = j+1;
            j = lps[i-1];
        } else {
            if(j == 0){
                lps[i++] = 0;
            } else {
                j = lps[j-1];
            }
        }
    }
    return lps;
}

int Solution::strStr(const string A, const string B) {
    int la = A.length(), lb = B.length();
    if(!lb) return -1;
    if(!la and !lb) return -1;
    vector<int> lps = get_lps(B);
    int p1 = 0, p2 = 0;
    while(p1<la and p2<lb){
        if(A[p1] == B[p2]){
            p1++;
            p2++;
        } else {
            if(p2 == 0) p1++;
            else p2 = lps[p2-1];
        }
    }
    if(p2 == lb) return p1-lb;
    return -1;
}
