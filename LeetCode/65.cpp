// https://leetcode.com/problems/valid-number/

class Solution {
public:
    bool isNumber(string A) {
        int st = 0, n = A.length(), end = n-1, p1;
        while(st < n) if(A[st] == ' ') st++; else break;
        while(end >= st) if(A[end] == ' ') end--; else break;
        if(st <= end and (A[st] == '-' or A[st] == '+')) st++;
        if(st > end) return 0;
        if(st == end and !isdigit(A[st])) return 0;
        bool num = 0, decimal = 0, e = 0;
        p1 = st;
        while(p1<=end){
            if(!isdigit(A[p1])){
                if(A[p1] == '.'){
                    if(e or decimal or (p1==st and p1+1<=end and !isdigit(A[p1+1]))) return 0;
                    decimal = 1;
                } else if(A[p1] == 'e'){
                    if(e or p1 == st or p1 == end or (!isdigit(A[p1+1]) and A[p1+1] != '-' and A[p1+1] != '+') or ((A[p1+1] == '-' or A[p1+1] == '+') and (p1+2>end or !isdigit(A[p1+2])))) return 0;
                    if(A[p1+1] == '-' or A[p1+1] == '+') p1++;
                    e = 1;
                } else {
                    return 0;
                }
            }
            p1++;
        }
        return 1;
    }
};