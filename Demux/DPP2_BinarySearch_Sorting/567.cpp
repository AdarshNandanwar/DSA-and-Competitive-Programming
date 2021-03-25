// https://leetcode.com/problems/permutation-in-string/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l1 = s1.length(), l2 = s2.length();
        unordered_map<int, int> fm;
        for(auto c:s1) fm[c]--;
        int remaining = l1;
        int p1 = 0, p2 = 0;
        // [p1, p2)
        
        while(p2<l2){
            if(fm.find(s2[p2]) == fm.end()){
                while(p1<p2){
                    fm[s2[p1]]--;
                    remaining++;
                    p1++;
                }
                p1 = p2+1;
            } else {
                while(fm[s2[p2]]>=0){
                    fm[s2[p1]]--;
                    remaining++;
                    p1++;
                }
                fm[s2[p2]]++;
                remaining--;
            }
            p2++;
            if(remaining == 0){
                return true;
            }
        }
        return false;
    }
};