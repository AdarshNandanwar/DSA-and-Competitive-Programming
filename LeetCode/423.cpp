// https://leetcode.com/problems/reconstruct-original-digits-from-english/

// Method 1 (Optimized Logic):

class Solution {
public:
    string originalDigits(string s) {
        // 0 zero   =>  z
        // 1 one    =>  o
        // 2 two    =>  w
        // 3 three  =>  r
        // 4 four   =>  u
        // 5 five   =>  f
        // 6 six    =>  x
        // 7 seven  =>  s
        // 8 eight  =>  t
        // 9 nine   =>  remaining
        
        // checking order => 0246 1357 8
        
        vector<int> freq(26, 0), num(10,0);
        for(auto & c:s) freq[c-'a']++;
        
        // 0
        num[0] = freq['z'-'a'];
        freq['r'-'a'] -= num[0];
        freq['o'-'a'] -= num[0];
        
        // 2
        num[2] = freq['w'-'a'];
        freq['t'-'a'] -= num[2];
        freq['o'-'a'] -= num[2];
        
        // 4
        num[4] = freq['u'-'a'];
        freq['f'-'a'] -= num[4];
        freq['o'-'a'] -= num[4];
        freq['r'-'a'] -= num[4];
        
        // 6
        num[6] = freq['x'-'a'];
        freq['s'-'a'] -= num[6];
        freq['i'-'a'] -= num[6];
        
        // 1
        num[1] = freq['o'-'a'];
        
        // 3
        num[3] = freq['r'-'a'];
        freq['t'-'a'] -= num[3];
        
        // 5
        num[5] = freq['f'-'a'];
        freq['i'-'a'] -= num[5];
        
        // 7
        num[7] = freq['s'-'a'];
        
        // 8
        num[8] = freq['t'-'a'];
        freq['i'-'a'] -= num[8];
        
        // 9
        num[9] = freq['i'-'a'];
        
        string ans;
        for(auto i = 0; i<10; i++) ans += string(num[i], '0'+i);
        
        return ans;
    }
};

// Method 2 (Verbose Logic):

class Solution {
public:
    string originalDigits(string s) {
        // 0 zero   =>  z
        // 1 one    =>  o
        // 2 two    =>  w
        // 3 three  =>  r
        // 4 four   =>  u
        // 5 five   =>  f
        // 6 six    =>  x
        // 7 seven  =>  s
        // 8 eight  =>  t
        // 9 nine   =>  remaining
        
        // checking order => 0246 1357 8
        
        unordered_map<char, int> freq;
        for(auto & c:s) freq[c]++;
        
        vector<int> num(10,0);
        
        // 0
        num[0] = freq['z'];
        freq['z'] -= num[0];
        freq['e'] -= num[0];
        freq['r'] -= num[0];
        freq['o'] -= num[0];
        
        // 2
        num[2] = freq['w'];
        freq['t'] -= num[2];
        freq['w'] -= num[2];
        freq['o'] -= num[2];
        
        // 4
        num[4] = freq['u'];
        freq['f'] -= num[4];
        freq['o'] -= num[4];
        freq['u'] -= num[4];
        freq['r'] -= num[4];
        
        // 6
        num[6] = freq['x'];
        freq['s'] -= num[6];
        freq['i'] -= num[6];
        freq['x'] -= num[6];
        
        // 1
        num[1] = freq['o'];
        freq['o'] -= num[1];
        freq['n'] -= num[1];
        freq['e'] -= num[1];
        
        // 3
        num[3] = freq['r'];
        freq['t'] -= num[3];
        freq['h'] -= num[3];
        freq['r'] -= num[3];
        freq['e'] -= num[3];
        freq['e'] -= num[3];
        
        // 5
        num[5] = freq['f'];
        freq['f'] -= num[5];
        freq['i'] -= num[5];
        freq['v'] -= num[5];
        freq['e'] -= num[5];
        
        // 7
        num[7] = freq['s'];
        freq['s'] -= num[7];
        freq['e'] -= num[7];
        freq['v'] -= num[7];
        freq['e'] -= num[7];
        freq['n'] -= num[7];
        
        // 8
        num[8] = freq['t'];
        freq['e'] -= num[8];
        freq['i'] -= num[8];
        freq['g'] -= num[8];
        freq['h'] -= num[8];
        freq['t'] -= num[8];
        
        // 9
        num[9] = freq['i'];
        freq['n'] -= num[9];
        freq['i'] -= num[9];
        freq['n'] -= num[9];
        freq['e'] -= num[9];
        
        string ans;
        for(auto i = 0; i<10; i++){
            ans += string(num[i], '0'+i);
        }
        
        return ans;
    }
};