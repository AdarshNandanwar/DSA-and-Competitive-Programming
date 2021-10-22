// https://leetcode.com/problems/reverse-words-in-a-string/

// Method 1 (2 Pointers, O(n) time, O(1) space):
class Solution {
public:
    
    void substring(string & s, int start, int len){
        // substring function in constant space
        int p1 = 0, p2 = start, n = s.length();
        while(p2<n and len){
            s[p1++] = s[start++];
            len--;
        }
        while(p1<s.length()) s.pop_back();
    }
    
    string reverseWords(string s) {
        // reversing logic
        int p1 = 0, p2 = 0, n = s.length();
        while(p2<n){
            while(p1<n and s[p1] == ' ') p1 = p2 = p1+1;
            while(p2<n and s[p2] != ' ') p2++;
            reverse(s.begin()+p1, s.begin()+p2);
            p1 = p2;
        }
        reverse(s.begin(), s.end());
        
        // remove leading zeros
        p1 = 0;
        while(p1<n and s[p1] == ' ') p1++;
        substring(s, p1, s.length()-p1);
        
        // remove trailing zeros
        p1 = s.length()-1;
        while(p1>=0 and s[p1] == ' ') p1--;
        substring(s, 0, p1+1);
        
        // remove repeated zeros
        p1 = 0; p2 = 0;
        while(p2<s.length()){
            if(s[p2] == ' ' and p1-1>=0 and s[p1-1] == ' ') p2++;
            else s[p1++] = s[p2++];
        }
        substring(s, 0, p1);
        
        return s;
    }
};

// Method 2 (InputStringStream, O(n) time, O(n) space):

class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);
        string cur, ans ="";
        while(getline(iss, cur, ' ')){
            if(cur.length() == 0) continue;
            if(ans.length() == 0) ans = cur;
            else ans = cur+" "+ans;
        }
        return ans;
    }
};