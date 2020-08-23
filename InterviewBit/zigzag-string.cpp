// https://www.interviewbit.com/problems/zigzag-string/

string Solution::convert(string A, int B) {
    if(B <= 0) return "";
    if(B == 1) return A;
    int sz = 2*B-2, n = A.length();
    string res = "";
    for(int r = 0; r<B; r++){
        for(int i = 0; i<n+sz; i += sz){
            if(0<=i-r and i-r<n and A[i-r] != '-'){
                res.push_back(A[i-r]);
                A[i-r] = '-';
            }
            if(i+r<n and A[i+r] != '-'){
                res.push_back(A[i+r]);
                A[i+r] = '-';
            }
        }
    }
    return res;
}
