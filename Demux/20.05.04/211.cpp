// https://leetcode.com/problems/add-and-search-word-data-structure-design/

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

class WordDictionary {
public:
    
    Node * root;

    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Node;    // dummy
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        int n = word.size();
        Node * curr = root;
        for(int i = 0; i<n; i++){
            if(curr->next[word[i]-'a'] == NULL)
                curr->next[word[i]-'a'] = new Node;
            curr = curr->next[word[i]-'a'];
        }
        curr->is_word = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    
    bool searchHelper(string & word, int index, Node * curr){
        if(index == word.size())
           return curr->is_word;
        
        if(word[index] != '.'){
            if(curr->next[word[index]-'a'] == NULL)
                return false;
            return searchHelper(word, index+1, curr->next[word[index]-'a']);
        } else {
            for(int i = 0; i<26; i++){
                if(curr->next[i] and searchHelper(word, index+1, curr->next[i]))
                    return true;
            }
            return false;
        }
    }
    
    bool search(string word) {
        return searchHelper(word, 0, root);        
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */