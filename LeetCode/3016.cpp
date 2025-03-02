// https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/

// Method 1 (Sorting, O(nlogn)):

class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        vector<int> freq(26);
        for(int i = 0; i<n; i++){
            freq[word[i]-'a']++;
        }

        int pushes = 0;
        sort(freq.begin(), freq.end(), greater<int>());
        for(int i=0; i<8; i++){
            pushes += (1 * freq[i]);
        }
        for(int i=8; i<16; i++){
            pushes += (2 * freq[i]);
        }
        for(int i=16; i<24; i++){
            pushes += (3 * freq[i]);
        }
        for(int i=24; i<26; i++){
            pushes += (4 * freq[i]);
        }

        return pushes;
    }
};
