// https://www.interviewbit.com/problems/fraction/

// Method 1:

string Solution::fractionToDecimal(int a, int b) {
    long A = a, B = b;
    string sign = (A<0)==(B<0) ? "" : "-";
    if(A%B == 0) return to_string(A/B);
    A = abs(A);
    B = abs(B);
    long rem = A%B, q = 0;
    unordered_map<long, long> m;
    m[rem] = 0;
    string decimal;
    while(rem){
        decimal += to_string((rem*10)/B);
        rem = (rem*10)%B;
        if(m.count(rem)){
            decimal = decimal.substr(0, m[rem])+"("+decimal.substr(m[rem])+")";
            break;
        }
        m[rem] = decimal.size();
    }
    return sign+to_string(A/B)+"."+decimal;
}
