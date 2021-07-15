// https://leetcode.com/problems/palindrome-pairs/

// Method 1 (binsry serach, O(n*l*logn)):

bool is_palindrome(string s){
    int i = 0, j = s.length()-1;
    while(i<=j) if(s[i++] != s[j--]) return 0;
    return 1;
}

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        int n = words.size();
        vector<pair<string, int>> rev_words;
        for(int i = 0; i<n; i++){
            rev_words.push_back(make_pair(string(words[i].rbegin(), words[i].rend()), i));
        }
        sort(rev_words.begin(), rev_words.end());
        for(int i = 0; i<n; i++){
            int j = 0;
            while(j<words[i].length()){
                if(!is_palindrome(words[i].substr(j))){
                    j++;
                    continue;
                } 
                string prefix = words[i].substr(0, j);
                auto it = lower_bound(rev_words.begin(), rev_words.end(), make_pair(prefix, 0));
                if(it != rev_words.end() and it->first == prefix and it->second != i){
                    res.push_back({i, it->second});
                }                
                j++;
            }
            auto it = lower_bound(rev_words.begin(), rev_words.end(), make_pair(words[i], 0));
            while(it != rev_words.end() and it->first.substr(0, j) == words[i]){
                if(it->second != i and is_palindrome(it->first.substr(words[i].length()))){
                    res.push_back({i, it->second});
                }
                it++;
            }
        }
        return res;
    }
};

// Method 2 (Brute Force, O(n*n*l), TLE):

bool is_palindrome(string s){
    int i = 0, j = s.length()-1;
    while(i<=j) if(s[i++] != s[j--]) return 0;
    return 1;
}

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        int n = words.size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(i == j) continue;
                if(is_palindrome(words[i]+words[j])){
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
};