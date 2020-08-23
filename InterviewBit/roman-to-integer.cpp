// https://www.interviewbit.com/problems/roman-to-integer/

int Solution::romanToInt(string A) {
    int n = A.length();
    unordered_map<char, int> m;
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;
    int maxVal = 0, res = 0;
    for(int i = n-1; i>=0; i--){
        if(m[A[i]] < maxVal) res -= m[A[i]];
        else res += m[A[i]];
        maxVal = max(maxVal, m[A[i]]);
    }
    return res;
}
