// https://www.interviewbit.com/problems/roman-to-integer/

// Method 1:

int Solution::romanToInt(string A) {
    int res = 0, n = A.length();
    unordered_map<char, int> m;
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;
    for(int i = 0; i<n; i++){
        if(i+1<n and m[A[i]] < m[A[i+1]]) res -= m[A[i]];
        else res += m[A[i]];
    }
    return res;
}

// Method 2 (Rules):

int Solution::romanToInt(string A) {
    int res = 0, n = A.length();
    for(int i = 0; i<n; i++){
        if(A[i] == 'I'){
            if(i+1 < n and (A[i+1] == 'V' or A[i+1] == 'X')){
                res -= 1;
            } else {
                res += 1;
            }
        } else if(A[i] == 'V'){
            res += 5;
        } else if(A[i] == 'X'){
            if(i+1 < n and (A[i+1] == 'L' or A[i+1] == 'C')){
                res -= 10;
            } else {
                res  += 10;
            }
        } else if(A[i] == 'L'){
            res += 50;
        } else if(A[i] == 'C'){
            if(i+1 < n and (A[i+1] == 'D' or A[i+1] == 'M')){
                res -= 100;
            } else {
                res  += 100;
            }
        } else if(A[i] == 'D'){
            res += 500;
        } else if(A[i] == 'M'){
            res += 1000;
        }
    }
    return res;
}
