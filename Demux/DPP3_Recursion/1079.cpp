// https://leetcode.com/problems/letter-tile-possibilities/

// Method 1 (Permutations on subsets):

class Solution {
public:
    int fact(int n){
        if(n == 0) return 1;
        return n*fact(n-1);
    }
    
    void helper(const string & tiles, int st, vector<int> & freq, int len, int & ans){
        int n = tiles.size();
        
        if(len){
            int num = fact(len), den = 1;
            for(int i = 0; i<26; i++){
                den *= fact(freq[i]);
            }
            ans += (num/den);
        }
        
        if(st == n) return;
        
        for(int i = st; i<n; i++){
            if(i != st and tiles[i] == tiles[i-1]) continue;
            freq[tiles[i]-'A']++;
            helper(tiles, i+1, freq, len+1, ans);
            freq[tiles[i]-'A']--;
        }
    }
    
    int numTilePossibilities(string tiles) {
        int n = tiles.length(), ans = 0;
        vector<int> freq(26, 0);
        sort(tiles.begin(), tiles.end());
        helper(tiles, 0, freq, 0, ans);
        return ans;
    }
};

// Method 2 (Selecting one by one):

class Solution {
public:
    void solve(unordered_map<char, int> & freq, int & count){
        for(auto & [i, f]:freq){
            if(f){
                f--;
                count++;
                solve(freq, count);
                f++;
            }
        }
    }
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> freq;
        for(auto i:tiles) freq[i]++;
        int count = 0;
        solve(freq, count);
        return count;
    }
};