// https://leetcode.com/problems/bulls-and-cows/

// Method 1:

class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> freq;
        int bulls = 0, cows = 0, n = secret.size();
        for(int i=0; i<n; i++){
            if(guess[i] == secret[i]){
                bulls++;
            } else {
                freq[secret[i]]++;
            }
        }
        for(int i=0; i<n; i++){
            if(guess[i] != secret[i] and freq[guess[i]] > 0){
                freq[guess[i]]--;
                cows++;
            }
        }
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};