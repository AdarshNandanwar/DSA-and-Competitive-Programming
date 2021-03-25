// https://www.interviewbit.com/problems/amazing-subarrays/

#define MOD 10003

int Solution::solve(string A) {
    int n = A.length(), res = 0;
    for(int i = 0; i<n; i++){
        if(isalpha(A[i]) and (tolower(A[i]) == 'a' or tolower(A[i]) == 'e' or tolower(A[i]) == 'i' or tolower(A[i]) == 'o' or tolower(A[i]) == 'u'))
            res = (res + (n-i))%MOD;
    }
    return res;
}
