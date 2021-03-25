// https://leetcode.com/problems/permutation-sequence/

// Method 1 (Recursion, O(n2)):

class Solution {
public:
    unordered_map<long, long> fact;

    long getFact(long n){
        if(n <= 1) return fact[n] = 1;
        return fact[n] = n*getFact(n-1);
    }

    void helper(long A, long B, unordered_set<long> & used, string & cur){
        if(B == 0){
            for(long i = 1; i<=A; i++){
                if(!used.count(i)) cur += to_string(i);
            }
            return;
        }
        long unUsed = A-used.size(), i;
        long bucket = B/getFact(unUsed-1);
        long b = bucket;
        for(i = 1; i<=A; i++){
            if(!used.count(i)) b--;
            if(b < 0) break;
        }
        cur = cur+to_string(i);
        used.insert(i);
        helper(A, B-bucket*getFact(unUsed-1), used, cur);
    }
    
    string getPermutation(int A, int B) {
        string cur = "";
        unordered_set<long> used;
        helper(A, B-1, used, cur);
        return cur;
    }
};