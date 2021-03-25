// https://leetcode.com/problems/implement-trie-prefix-tree/

struct Node {
    bool is_word;
    Node * next[26];
    Node(){
        is_word = false;
        for(int i = 0; i<26; i++){
            next[i] = NULL;
        }
    }
};

class Trie {
public:
    
    Node * root;
    
    /** Initialize your data structure here. */
    Trie() {
        root = new Node;    // dummy
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int n = word.size();
        Node * curr = root;
        for(int i = 0; i<n; i++){
            if(curr->next[word[i]-'a'] == NULL)
                curr->next[word[i]-'a'] = new Node;
            curr = curr->next[word[i]-'a'];
        }
        curr->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int n = word.size();
        Node * curr = root;
        for(int i = 0; i<n; i++){
            if(curr->next[word[i]-'a'] == NULL)
                return false;
            curr = curr->next[word[i]-'a'];
        }
        return curr->is_word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int n = prefix.size();
        Node * curr = root;
        for(int i = 0; i<n; i++){
            if(curr->next[prefix[i]-'a'] == NULL)
                return false;
            curr = curr->next[prefix[i]-'a'];
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