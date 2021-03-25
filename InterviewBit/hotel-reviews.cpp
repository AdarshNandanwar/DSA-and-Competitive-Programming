// https://www.interviewbit.com/problems/hotel-reviews/

//  Method 1 (Trie):

struct TrieNode{
    bool isWord;
    TrieNode * next[26];
    TrieNode(){
        isWord = 0;
        for(int i = 0; i<26; i++){
            next[i] = NULL;
        }
    }
};

int getCV(string s, TrieNode * root){
    int count = 0;
    istringstream iss(s);
    string w;
    TrieNode * cur;
    while(getline(iss, w, '_')){
        bool brk = 0;
        cur = root;
        // search in trie
        for(auto c:w){
            if(cur->next[c-'a'] == NULL){
                brk = 1;
                break;
            } 
            cur = cur->next[c-'a'];
        }
        if(!brk and cur->isWord) count++;
    }
    return count;
}

vector<int> Solution::solve(string A, vector<string> &B) {
    int n = B.size();
    TrieNode dummy;
    TrieNode * cur;
    istringstream iss(A);
    string cw;
    while(getline(iss, cw, '_')){
        cur = &dummy;
        // insert in trie
        for(auto c:cw){
            if(cur->next[c-'a'] == NULL) cur->next[c-'a'] = new TrieNode();
            cur = cur->next[c-'a'];
        }
        cur->isWord = 1;
    }
    vector<int> cv(n, 0);
    for(int i = 0; i<n; i++) cv[i] = getCV(B[i], &dummy);
    vector<int> res;
    for(int i = 0; i<n; i++){
        res.push_back(i);
    }
    sort(res.begin(), res.end(), [&cv](const int & a, const int & b){
        return cv[a] == cv[b] ? a<b : cv[a]>cv[b];
    });
    return res;
}
