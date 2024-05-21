// https://leetcode.com/problems/custom-sort-string/

// Method 1 (Couting Sort, O(n)):

class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> freq(26, 0);
        for(const char c:s){
            freq[c-'a']++;
        }
        string res;
        for(const char c:order){
            res += string(freq[c-'a'], c);
            freq[c-'a'] = 0;
        }
        for(int i=0; i<26; i++){
            if(freq[i] > 0){
                res += string(freq[i], i+'a');
            }
        }
        return res;
    }
};

// Method 2 (Custom Comparator, O(nlogn)):

class Solution {
public:
    string customSortString(string order, string str) {
        vector<int> pos(26, 26);
        for(int i = 0; i<order.length(); i++) pos[order[i]-'a'] = i;
        sort(str.begin(), str.end(), [&pos](const char & a, const char & b){
            return pos[a-'a'] < pos[b-'a'];
        });
        return str;
    }
};