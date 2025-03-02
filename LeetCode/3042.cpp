// https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/

// Method 1 (Brute Force, O(l*n2)):

class Solution {
    bool helper(const string & s1, const string & s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        if(n1 > n2){
            return false;
        }
        for(int i=0; i<n1; i++){
            if(s1[i] != s2[i] or s1[n1-1-i] != s2[n2-1-i]){
                return false;
            }
        }
        return true;
    }
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(helper(words[i], words[j])){
                    count++;
                }
            }
        }
        return count;
    }
};
