// https://leetcode.com/problems/prefix-and-suffix-search/

// Method 1 (Trie):

struct Trie{
    int index;
    Trie * next[27];
    Trie(){
        this->index = -1;
        for(int i = 0; i<27; i++) this->next[i] = NULL;
    }
};

class WordFilter {
public:
    
    Trie * root;
    
    void insert(string s, int index){
        Trie * cur = root;
        for(auto & c:s){
            if(cur->next[c-'a'] == NULL){
                cur->next[c-'a'] = new Trie();
            }
            cur->index = max(cur->index, index);
            cur = cur->next[c-'a'];
        }
        cur->index = max(cur->index, index);
    }  
    
    int count(string s){
        Trie * cur = root;
        for(auto & c:s){
            if(cur->next[c-'a'] == NULL) return -1;
            cur = cur->next[c-'a'];
        }
        return cur->index;
    }  
    
    WordFilter(vector<string>& words) {
        root = new Trie();
        for(int i = 0; i<words.size(); i++){
            for(int j = 1; j<=words[i].length(); j++){
                for(int k = 0; k<words[i].length(); k++){
                    insert(words[i].substr(k)+"{"+words[i].substr(0, j), i);
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        return count(suffix+"{"+prefix);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */