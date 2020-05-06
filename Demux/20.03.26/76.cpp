// https://leetcode.com/problems/minimum-window-substring/

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> m;
        int n = s.size(), M = t.size();
        int remaining = M;
        // Set all required letter as -1 to differentiate them
        // Even supports multiple occurence of a letter
        for(int i = 0; i<M; i++){
            m[t[i]]--;
        }
        int left = 0, right = 0, start = 0, end = 0;
        while(right <= n){
            if(remaining){
                m[s[right]]++;
                if(m[s[right]] <= 0){   // '<' is for multiple occurence of a letter
                    remaining--;
                }
                right++;
            } else {
                if(end == 0 || end-start > right-left){
                    start = left;
                    end = right;
                }
                m[s[left]]--;
                if(m[s[left]] <= -1){   // '<' is for multiple occurence of a letter
                    remaining++;
                }
                left++;
            }
        }
        return s.substr(start, end-start);
    }
};