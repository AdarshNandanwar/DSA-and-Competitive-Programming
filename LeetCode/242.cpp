// https://leetcode.com/problems/valid-anagram/

// Method 1 (Hash Maps, O(n)):

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        unordered_map<char, int> freq;
        for(auto &c:s){
            freq[c]++;
        }
        for(auto &c:t){
            freq[c]--;
        }
        for(char c='a'; c<='z'; c++){
            if(freq[c]){
                return false;
            }
        }
        return true;
    }
};

// Method 2 (Hash Maps, O(n)):

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        int nonZero = 0;
        unordered_map<char, int> freq;
        for(auto &c:s){
            if(freq[c] == 0){
                nonZero++;
            }
            freq[c]++;
        }
        for(auto &c:t){
            if(freq[c] == 0){
                nonZero++;
            }
            freq[c]--;
            if(freq[c] == 0){
                nonZero--;
            }
        }
        return nonZero == 0;
    }
};

// Method 3 (Sorting, O(nlogn)):

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s==t;
    }
};