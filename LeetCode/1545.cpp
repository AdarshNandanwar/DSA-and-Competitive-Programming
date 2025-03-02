// https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/

// Method 1 (Recursion, O(n)):

class Solution {
public:
    char findKthBit(int n, int k) {
        if(n == 1){
            return '0';
        }
        int len = (1<<n) - 1;
        int mid = len / 2;

        char res;
        if(k-1 == mid){
            res = '1';
        } else if(k-1 < mid){
            res = findKthBit(n-1, k);
        } else {
            res = findKthBit(n-1, len-k+1);
            res = res == '0' ? '1' : '0';
        }

        return res;
    }
};

// Method 2 (Recursion, O(2^n)):

class Solution {
    string helper(int n){
        if(n == 1){
            return "0";
        }

        string h = helper(n-1);
        int hLen = h.length();
        string res = h + "1" + h;
        int len = res.length();

        int p1 = len-hLen, p2 = len-1;
        while(p1 < p2){
            swap(res[p1], res[p2]);
            p1++;
            p2--;
        }
        for(int i=len-hLen; i<len; i++){
            res[i] = res[i] == '0' ? '1' : '0';
        }
        
        return res;
    }
public:
    char findKthBit(int n, int k) {
        return helper(n)[k-1];
    }
};
