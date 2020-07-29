// https://leetcode.com/problems/minimum-window-substring/

class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length() == 0) return "";
        int n = s.length(), p1 = 0, p2 = 0, remaining = t.length(), st = 0, end = 0;
        unordered_map<char, int> freq;
        // Set all required letter as -1 to differentiate them
        // Even supports multiple occurence of a letter
        for(auto i:t) freq[i]--;

        // s[p1..p2)
        while(p2<n){

            while(p2<n and remaining){
                freq[s[p2]]++;
                if(freq[s[p2]] <= 0) remaining--;   // '<' is for multiple occurence of a letter
                p2++;
            }

            while(p1<p2 and !remaining){
                if(end == 0 or end-st > p2-p1){
                    st = p1; 
                    end = p2;
                } 
                freq[s[p1]]--;
                if(freq[s[p1]] < 0) remaining++;
                p1++;
            }
        }
        return s.substr(st, end-st);
    }
};