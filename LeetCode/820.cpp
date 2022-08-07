// https://leetcode.com/problems/short-encoding-of-words/

// Method 1 (Trie, O(n*l)):

class Solution {
    struct TrieNode {
        TrieNode * next[26];
        TrieNode(){
            for(int i=0; i<26; i++){
                next[i] = NULL;
            }
        }
    };
    void traverseTrie(TrieNode * root, int curLen, int & totalLen, int & leafCount){
        bool isLeaf = true;
        for(int i=0; i<26; i++){
            if(root->next[i]){
                isLeaf = false;
                traverseTrie(root->next[i], curLen+1, totalLen, leafCount);
            }
        }
        if(isLeaf){
            totalLen += curLen;
            leafCount++;
        }
    }
public:
    int minimumLengthEncoding(vector<string>& words) {
        TrieNode * root = new TrieNode();
        for(auto &word:words){
            TrieNode * cur = root;
            reverse(word.begin(), word.end());
            for(auto &c:word){
                if(cur->next[c-'a'] == NULL){
                    cur->next[c-'a'] = new TrieNode();
                }
                cur = cur->next[c-'a'];
            }
        }
        int totalLen = 0, leafCount = 0;
        traverseTrie(root, 0, totalLen, leafCount);
        return totalLen+leafCount;
    }
};

// Method 2 (Sorting, Binary Search, O(n*l*logn)):

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string & a, const string & b){
            return a.length() > b.length();
        });
        set<string> s;
        for(auto &word:words){
            reverse(word.begin(), word.end());
            int wordLen = word.length();
            auto itr = s.lower_bound(word);
            if(itr == s.end()){
                s.insert(word);
            } else {
                auto next = *itr;
                if(next.length() < wordLen or next.substr(0, wordLen) != word){
                    s.insert(word);
                }
            }
        }
        auto res = s.size();
        for(auto & word:s){
            res += word.length();
        }
        return res;
    }
};