// https://www.interviewbit.com/problems/valid-number/

int Solution::isNumber(const string A) {
    int st = 0, p1 = 0, n = A.length();
    while(st < n) if(A[st] == ' ') st++; else break;
    if(st < n and A[st] == '-') st++;
    string s = A.substr(st);
    p1 = 0, n = s.length();
    if(n == 0) return 0;
    bool decimal = 0, e = 0;
    while(p1<n){
        if(!isdigit(s[p1])){
            if(s[p1] == '.'){
                if(e or decimal or p1 == n-1 or !isdigit(s[p1+1])) return 0;
                decimal = 1;
            } else if(s[p1] == 'e'){
                if(e or p1 == n-1 or (!isdigit(s[p1+1]) and s[p1+1] != '-')) return 0;
                if(s[p1+1] == '-') p1++;
                e = 1;
            } else {
                while(p1<n) if(s[p1++] != ' ') return 0;
                return 1;
            }
        }
        p1++;
    }
    return 1;
}
