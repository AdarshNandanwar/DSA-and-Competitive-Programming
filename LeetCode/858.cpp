// https://leetcode.com/problems/mirror-reflection/

// Method 1 (Math, Euler HCF, O(log(min(p,q)))):

class Solution {
    int getHcf(int a, int b){
        if(b == 0) return a;
        return getHcf(b, a%b);
    }
    int getLcm(int a, int b){
        return (a*b)/getHcf(a, b);
    }
public:
    int mirrorReflection(int p, int q) {
        int lcm = getLcm(p, q);
        if((lcm/p)%2 == 0){
            // south
            return 0;
        } else {
            // north
            if((lcm/q)%2 == 0){
                return 2;
            } else {
                return 1;
            }
        }
    }
};