// https://leetcode.com/problems/number-of-wonderful-substrings/

// Method 1 (Bitmask, Hashing, Time and Space Optimization, O(n) time, O(1) space):

class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int n = word.size();
        
        int isOddFreqBitmask = 0;
        vector<int> bitmaskFreq(1024);
        bitmaskFreq[0]++;

        long long res = 0;
        for(char c:word){
            int index = c-'a';

            isOddFreqBitmask ^= (1<<index);

            // No odd-even mismatch => No letter appears odd number of times in substring
            res += bitmaskFreq[isOddFreqBitmask];

            for(int i=0; i<10; i++){
                // One odd-even mismatch allowed => 1 letter appears odd number of times in substring
                res += bitmaskFreq[(isOddFreqBitmask^(1<<i))];
            }

            bitmaskFreq[isOddFreqBitmask]++;
        }

        return res;
    }
};

// Method 2 (Bitmask, Hashing, O(n) time, O(1) space):

class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int n = word.size();
        vector<int> freq(10);
        int isOddFreqBitmask = 0;
        unordered_map<int, int> bitmaskFreq;
        bitmaskFreq[0]++;
        long long res = 0;
        for(char c:word){
            int index = c-'a';

            freq[index]++;
            if(freq[index]%2 == 1){
                // Set bit
                isOddFreqBitmask |= (1<<index);
            } else {
                // Unset bit
                isOddFreqBitmask &= (~(1<<index));
            }

            if(bitmaskFreq.count(isOddFreqBitmask)){
                // No odd-even mismatch => No letter appears odd number of times in substring
                res += bitmaskFreq[isOddFreqBitmask];
            }

            for(int i=0; i<10; i++){
                // One odd-even mismatch allowed => 1 letter appears odd number of times in substring
                int mask = (isOddFreqBitmask ^ (1<<i));
                if(bitmaskFreq.count(mask)){
                    res += bitmaskFreq[mask];
                }
            }

            bitmaskFreq[isOddFreqBitmask]++;
        }

        return res;
    }
};
