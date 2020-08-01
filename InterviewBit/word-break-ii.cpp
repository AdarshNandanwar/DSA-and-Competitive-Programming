// https://www.interviewbit.com/problems/word-break-ii/

// Method 1 (Trie)

struct TrieNode{
    bool isWord;
    string val;
    TrieNode * next[128];
    TrieNode(){
        isWord = false;
        val = "";
        for(int i = 0; i<128; i++){
            next[i] = NULL;
        }
    }
};

void helper(string & s, int index, TrieNode & dummy, TrieNode * cur, string & curStr, vector<string> & ans){
    if(cur == NULL) return;
    if(index == s.length()){
        if(cur->isWord){
            string entry;
            if(curStr.length()) entry = curStr + " " + cur->val;
            else entry = cur->val;
            ans.push_back(entry);
        }
        return;
    }
    
    if(cur->isWord){
        string temp;
        if(curStr.length()) temp = curStr + " " + cur->val;
        else temp = cur->val;
        helper(s, index+1, dummy, dummy.next[s[index]], temp, ans);
    }
    
    if(cur->next[s[index]]){
        helper(s, index+1, dummy, cur->next[s[index]], curStr, ans);
    }
}

vector<string> Solution::wordBreak(string s, vector<string> &wordDict) {
        
    // checking if the string can be partitioned
    int ns = s.length();
    unordered_set<string> us;
    for(auto w:wordDict) us.insert(w);
    // partitionable[i] = if [i, n) is partitionable ?
    vector<bool> partitionable(ns+1, 0);
    partitionable[ns] = 1;
    for(int i = ns-1; i>=0; i--){
        string cur = "";
        for(int j = i; j<ns; j++){
            cur.push_back(s[j]);
            if(us.count(cur) and partitionable[j+1]){
                partitionable[i] = 1;
                break;
            }
        }
    }
    
    if(partitionable[0] == 0) return vector<string>();
    
    TrieNode dummy;
    TrieNode * cur = &dummy;
    
    // insert into trie
    for(auto w:wordDict){
        if(w.length() == 0) continue;
        cur = &dummy;
        for(auto c:w){
            if(cur->next[c] == NULL) cur->next[c] = new TrieNode();
            cur = cur->next[c];                
        }
        cur->val = w;
        cur->isWord = 1;
    }
    
    vector<string> ans;
    string curStr = "";
    helper(s, 0, dummy, &dummy, curStr, ans);
    return ans;
}
