// https://leetcode.com/problems/implement-trie-prefix-tree/

// Method 1 (using new TrieNode class object):

class Trie {
    class TrieNode {
    public:
        bool isWord;
        vector<TrieNode *> next;

        TrieNode(){
            next = vector<TrieNode *>(26, NULL);
            isWord = false;
        }
    };
    TrieNode * root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode * cur = root;
        for(auto &c:word){
            if(cur->next[c-'a'] == NULL){
                cur->next[c-'a'] = new TrieNode();
            }
            cur = cur->next[c-'a'];
        }
        cur->isWord = true;
    }
    
    bool search(string word) {
        TrieNode * cur = root;
        for(auto &c:word){
            if(cur->next[c-'a'] == NULL){
                return false;
            }
            cur = cur->next[c-'a'];
        }
        return cur->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode * cur = root;
        for(auto &c:prefix){
            if(cur->next[c-'a'] == NULL){
                return false;
            }
            cur = cur->next[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

// Method 2 (using this):

class Trie {
public:
    
    Trie * next[26];
    bool isWord;
    
    Trie() {
        isWord = false;
        for(int i=0; i<26; i++) next[i] = NULL;
    }
    
    void insert(string word) {
        Trie * cur = this;
        for(auto &c:word){
            if(!cur->next[c-'a']) cur->next[c-'a'] = new Trie();
            cur = cur->next[c-'a'];
        }
        cur->isWord = true;
    }
    
    bool search(string word) {
        Trie * cur = this;
        for(auto &c:word){
            if(!cur->next[c-'a']) return false;
            cur = cur->next[c-'a'];
        }
        return cur->isWord;
    }
    
    bool startsWith(string prefix) {
        Trie * cur = this;
        for(auto &c:prefix){
            if(!cur->next[c-'a']) return false;
            cur = cur->next[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */