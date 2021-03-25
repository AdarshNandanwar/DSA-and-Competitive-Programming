// https://www.interviewbit.com/problems/atoi/

int Solution::atoi(const string A) {
    long n = A.length(), res = 0, i = 0;
    while(i<n and A[i] == ' ') i++;
    bool isPos = 1;
    if(i<n and A[i] == '-'){
        isPos = 0;
        i++;
    } else if(i<n and A[i] == '+'){
        isPos = 1;
        i++;
    } 
    while(i<n and isdigit(A[i])){
        res = res*10+(A[i]-'0');
        if(isPos and res>INT_MAX) return INT_MAX;
        if(!isPos and -res<INT_MIN) return INT_MIN;
        i++;
    }
    return isPos ? res : -res;
}
