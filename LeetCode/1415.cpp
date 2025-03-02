// https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/

// Method 1 (Backtracking, O(n*k)):

class Solution {
    vector<char> letters = {'a', 'b', 'c'};

    void helper(const int n, const int k, string & cur, string & ans, int & pos, char prev){
        if(cur.length() == n){
            pos++;
            if(pos == k){
                ans = cur;
            }
            return;
        }
        if(pos >= k){
            return;
        }
        
        for(char c:letters){
            if(c == prev){
                continue;
            }
            cur.push_back(c);
            helper(n, k, cur, ans, pos, c);
            cur.pop_back();
        }
    }
public:
    string getHappyString(int n, int k) {
        string cur, ans;
        int pos = 0;
        helper(n, k, cur, ans, pos, '0');
        return ans;
    }
};
