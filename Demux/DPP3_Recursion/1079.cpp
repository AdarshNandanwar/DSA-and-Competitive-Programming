// https://leetcode.com/problems/letter-tile-possibilities/

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