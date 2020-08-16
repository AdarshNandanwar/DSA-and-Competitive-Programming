// https://leetcode.com/problems/fibonacci-number/

class Solution {
public:
    int fib(int N) {
        if(N <= 1) return N;
        int p1 = 0, p2 = 1, res;
        for(int i = 2; i<=N; i++){
            res = p1+p2;
            p1 = p2;
            p2 = res;
        }
        return res;
    }
};