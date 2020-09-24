// https://leetcode.com/problems/reorganize-string/

// Method 1 (Greedy, O(n)):

class Solution {
public:
    string reorganizeString(string S) {
        unordered_map<char, int> freq;
        int maxF = 0, n = S.length();
        char maxEle;
        if(n == 0) return "";
        for(auto c:S) {
            freq[c]++;
            if(maxF < freq[c]){
                maxF = freq[c];
                maxEle = c;
            }
        }
        
        if(maxF > (n+1)/2) return "";
        
        string res(n, ' ');
        int ind = 0;
        
        // seperating handling the case of maxEle
        for(int j = 0; j<maxF; j++){
            if(ind >= n) ind = 1;
            res[ind] = maxEle;
            ind += 2;
        }
        
        for(auto i:freq){
            if(i.first == maxEle) continue;
            for(int j = 0; j<i.second; j++){
                if(ind >= n) ind = 1;
                res[ind] = i.first;
                ind += 2;
            }
        }
        return res;
    }
};