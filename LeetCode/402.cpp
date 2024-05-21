// https://leetcode.com/problems/remove-k-digits/

// Method 1 (Stack, O(n)):

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();

        stack<int> incSt;
        vector<int> nextLower(n, n);
        incSt.push(0);
        for(int i=1; i<n; i++){
            while(!incSt.empty() and num[incSt.top()]>num[i]){
                nextLower[incSt.top()] = i;
                incSt.pop();
            }
            incSt.push(i);
        }

        string res;
        int next = 0;
        while(next < n){
            while(next < n and nextLower[next] != n and nextLower[next]-next <= k){
                k -= (nextLower[next]-next);
                next = nextLower[next];
            }
            if(next < n and !(num[next] == '0' and res == "")){
                res += num[next];
            }
            next++;
        }
        // Handle cases like: num = "111111" k = 3, num = "123456" k = 3
        int trimSuffixLength = min(k, (int)res.length());
        res = res.substr(0, res.length()-trimSuffixLength);
        return res == "" ? "0" : res;
    }
};
