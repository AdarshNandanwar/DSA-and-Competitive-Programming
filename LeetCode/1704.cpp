// https://leetcode.com/problems/determine-if-string-halves-are-alike/

class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.length(), sum = 0;
        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for(auto i = 0; i<n; i++){
            if(vowels.count(s[i])){
                sum += (i<n/2?1:-1);
            }
        }
        return sum == 0;
    }
};