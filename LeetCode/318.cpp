// https://leetcode.com/problems/maximum-product-of-word-lengths/

// Method 1 (Bit Masking, O(n2)):

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int res = 0, n = words.size();
        vector<int> mask(n, 0);
        for(int i = 0; i<n; i++){
            for(char c:words[i]){
                mask[i] |= 1<<(c-'a');
            } 
            for(int j = 0; j<i; j++){
                if(!(mask[i] & mask[j])) res = max(res, (int)(words[i].length()*words[j].length()));
            }
        }
        return res;
    }
};

// Alternate Code:

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size(), maxValue = 0;
        vector<int> bitMask(n, 0);
        for(int i=0; i<n; i++){
            for(auto &c:words[i]){
                bitMask[i] |= (1<<(c-'a'));
            }
        }
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if((bitMask[i] & bitMask[j]) == 0){
                    maxValue = max(maxValue, (int)(words[i].length()*words[j].length()));
                }                
            }
        }
        return maxValue;
    }
};