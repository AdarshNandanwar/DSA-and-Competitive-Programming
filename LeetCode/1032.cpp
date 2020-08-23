// https://leetcode.com/problems/stream-of-characters/

// Method 1 (Trie, O(words*feed));

class TrieNode {
    public:
    bool isWord;
    TrieNode * next[26];
    TrieNode(){
        isWord = 0;
        for(int i = 0; i<26; i++) next[i] = NULL;
    }
};

class StreamChecker {
public:
    
    TrieNode * root;
    string feed;
    
    StreamChecker(vector<string>& words) {
        root = new TrieNode();
        feed = "";
        //insert in Trie
        for(auto w:words){
            TrieNode * cur = root;
            int l = w.length();
            for(int i = l-1; i>=0; i--){
                if(cur->next[w[i]-'a'] == NULL) cur->next[w[i]-'a'] = new TrieNode();
                cur = cur->next[w[i]-'a'];
            }
            cur->isWord = 1;
        }
    }
    
    bool query(char letter) {
        feed.push_back(letter);
        // search in Trie
        TrieNode * cur = root;
        for(int i = feed.length()-1; i>=0; i--){
            if(cur->next[feed[i]-'a'] == NULL) return 0;
            cur = cur->next[feed[i]-'a'];
            if(cur->isWord) return 1;
        }
        return 0;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */