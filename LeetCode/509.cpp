// https://leetcode.com/problems/fibonacci-number/

// Method 1 (Iterative, o(n)):

class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        int prev = 1, prevPrev = 0;
        for(int i=2; i<=n; i++){
            swap(prev, prevPrev);
            prev += prevPrev;
        }
        return prev;
    }
};

// Alternate Code:

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

// Method 2 (Recursion, O(2^n)):

class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        return fib(n-1)+fib(n-2);
    }
};