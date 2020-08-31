// https://www.interviewbit.com/problems/xor-between-two-arrays/

// Method 1 (Triel, O(32*max(n+m))):

struct TrieNode {
    TrieNode * next[2];
    TrieNode(){
        next[0] = next[1] = NULL;
    }
};

int findBestXor(TrieNode * cur, int x){
    int best = 0;
    for(int i = 31; i>=0; i--){
        if((x>>i)&1){
            if(cur->next[0]){
                cur = cur->next[0];
            } else {
                best += (1<<i);
                cur = cur->next[1];
            }
        } else {
            if(cur->next[1]){
                best += (1<<i);
                cur = cur->next[1];
            } else {
                cur = cur->next[0];
            }
        }
    }
    return x^best;
}

int Solution::solve(vector<int> &A, vector<int> &B) {
    if(A.size() == 0 or B.size() == 0) return 0;
    TrieNode * root = new TrieNode(), * cur;
    
    // insert A in trie
    for(auto a:A){
        cur = root;
        for(int i = 31; i>=0; i--){
            if(cur->next[(a>>i)&1] == NULL) cur->next[(a>>i)&1] = new TrieNode();
            cur = cur->next[(a>>i)&1];
        }
    }
    
    int res = 0;
    for(auto b:B) res = max(res, findBestXor(root, b));
    return res;
}
