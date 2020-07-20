// https://leetcode.com/problems/find-all-anagrams-in-a-string/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length(), remaining = p.length();
        unordered_map<int, int> m;
        vector<int> res;
        for(auto i:p){
            m[i]--;
        }
        // [p1,p2)
        int p1 = 0, p2;
        for(p2 = 0; p2<p.length(); p2++){
            if(m[s[p2]] < 0) remaining--;
            m[s[p2]]++;
        }
        while(p2<=n){
            
            if(remaining == 0) res.push_back(p1);
            
            if(m[s[p2]] < 0) remaining--;
            m[s[p2]]++;
            
            if(m[s[p1]] <= 0) remaining++;
            m[s[p1]]--;
            
            p1++;
            p2++;
        }
        return res;
    }
};