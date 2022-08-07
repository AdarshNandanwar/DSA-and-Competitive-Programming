// https://leetcode.com/problems/minimum-window-substring/

// Method 1 (2 Pointer Window, O(n)):

class Solution {
public:
    string minWindow(string s, string t) {
        string ans = "";
        int ansLen = INT_MAX;
        int remaining = 0;
        unordered_map<char, int> freq;
        for(auto & c:t){
            freq[c]--;
            remaining++;
        }
        int n = s.length(), p1 = 0, p2 = 0;
        while(p2<n){
            while(remaining and p2<n){
                if(freq[s[p2]] < 0){
                    remaining--;
                }
                freq[s[p2]]++;
                p2++;
            }
            if(remaining){
                break;
            }
            while(remaining==0 and p1<=p2){
                freq[s[p1]]--;
                if(freq[s[p1]] < 0){
                    remaining++;
                }
                p1++;
            }
            if(ansLen > p2-(p1-1)){
                ansLen = p2-(p1-1);
                ans = s.substr(p1-1, ansLen);
            }
        }
        return ans;
    }
};