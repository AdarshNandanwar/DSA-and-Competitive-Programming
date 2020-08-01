// https://www.interviewbit.com/problems/shortest-unique-prefix/

struct TrieNode {
    bool isWord;
    int count;
    TrieNode * next[26];
    TrieNode(){
        isWord = 0;
        count = 0;
        for(int i = 0; i<26; i++) next[i] = NULL;
    }
};

vector<string> Solution::prefix(vector<string> &A) {
    
    vector<string> prefixes;
    
    TrieNode dummy;
    TrieNode * root = &dummy;
    
    // insert into trie
    for(auto s:A){
        TrieNode * cur = root;
        for(auto c:s){
            if(cur->next[c-'a'] == NULL){
                cur->next[c-'a'] = new TrieNode();
            }
            cur = cur->next[c-'a'];
            cur->count++;
        }
        cur->isWord = 1;
    }
    
    // get prefix form trie
    for(auto s:A){
        TrieNode * cur = root;
        int len = 0;
        for(auto c:s){
            len++;
            cur = cur->next[c-'a'];
            if(cur->count == 1){
                prefixes.push_back(s.substr(0, len));
                break;
            } 
        }
    }
    
    return prefixes;
}
