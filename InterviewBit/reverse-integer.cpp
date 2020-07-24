// https://www.interviewbit.com/problems/reverse-integer/

int Solution::reverse(int A) {
    bool pos = A >= 0;
    string s = to_string(abs(A));
    std::reverse(s.begin(), s.end());
    long res = stol(s);
    if((pos and res>INT_MAX) or (!pos and -res<INT_MIN)) return 0;
    return pos ? res : -res;
}
