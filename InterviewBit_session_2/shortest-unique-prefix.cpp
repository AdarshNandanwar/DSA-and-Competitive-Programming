// https://www.interviewbit.com/problems/shortest-unique-prefix/

// method 1 (Trie, O(n*len)):

struct TrieNode{
    TrieNode * next[128];
    bool is_word;
    int count;
    TrieNode(){
        for(int i = 0; i<128; i++){
            this->next[i] = NULL;
        }
        this->is_word = false;
        this->count = 0;
    }
};

string helper(TrieNode * root, string & s){
    for(int i = 0; i<s.length(); i++){
        root = root->next[s[i]];
        if(root->count == 1) return s.substr(0, i+1);
    }
    return s;
}

vector<string> Solution::prefix(vector<string> &A) {
    TrieNode * root = new TrieNode();

    // add words
    for(auto & s:A){
        TrieNode * cur = root;
        for(auto & c:s){
            if(cur->next[c] == NULL){
                cur->next[c] = new TrieNode();
            }
            cur->count++;
            cur = cur->next[c];
        }
        cur->count++;
        cur->is_word = 1;
    }

    vector<string> res;
    for(auto & s:A){
        res.push_back(helper(root, s));
    }
    return res;
}
