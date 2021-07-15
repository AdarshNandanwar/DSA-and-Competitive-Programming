// https://www.interviewbit.com/problems/atoi/

int Solution::atoi(const string A) {
    int i = 0, n = A.length();
    while(i<n and A[i] == ' ') i++;
    if(i == n) return 0;
    bool neg = A[i] == '-', pos = A[i] == '+';
    if(neg) i++;
    if(pos) i++;
    int res = 0, next;
    while(i<n and '0'<=A[i] and A[i]<='9'){
        int next = 10*res+A[i]-'0';
        i++;
        if(res != next/10) return neg ? INT_MIN : INT_MAX;
        res = next;
    }
    if(neg){
        return res == INT_MAX ? INT_MIN : -res;
    } else return res;
}
