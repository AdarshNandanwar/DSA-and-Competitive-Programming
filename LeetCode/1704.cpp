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

// Alternate Code:

class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.length(), vowelCount = 0;
        for(int i=0; i<n; i++){
            char c = tolower(s[i]);
            if(
                c == 'a' or
                c == 'e' or
                c == 'i' or
                c == 'o' or
                c == 'u'
            )
            {
                if(i<n/2){
                    vowelCount++;
                } else {
                    vowelCount--;
                }
            }
        }
        return vowelCount == 0;
    }
};