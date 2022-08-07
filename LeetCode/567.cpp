// https://leetcode.com/problems/permutation-in-string/

// Method 1 (Sliding window, O(n+m)):

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length(), m = s2.length(), neg = 0;
        vector<int> freq(26, 0);
        for(auto c:s1) freq[c-'a']++;
        for(int i=0; i<m; i++){
            freq[s2[i]-'a']--;            
            if(freq[s2[i]-'a']==-1) neg++;
            if(i-n>=0){
                freq[s2[i-n]-'a']++;            
                if(freq[s2[i-n]-'a']==0) neg--; 
            }
            if(i>=n-1 and neg==0) return true;
        }
        return false;
    }
};

// Method 2 (2 pointers, O(n+m)):

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