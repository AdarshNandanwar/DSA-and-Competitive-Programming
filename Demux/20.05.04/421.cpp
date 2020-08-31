// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/

// Method 1 (Trie, O(32*n), more optimized and clean code):

class Solution {
public:
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
    
    int findMaximumXOR(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        TrieNode * root = new TrieNode(), * cur;

        // insert A in trie
        for(auto a:nums){
            cur = root;
            for(int i = 31; i>=0; i--){
                if(cur->next[(a>>i)&1] == NULL) cur->next[(a>>i)&1] = new TrieNode();
                cur = cur->next[(a>>i)&1];
            }
        }

        int res = 0;
        for(auto a:nums) res = max(res, findBestXor(root, a));
        return res;
    }
};

// Method 1 (Trie, O(32*n)):

struct TrieNode{
    TrieNode * next[2];
    TrieNode(){
        next[0] = NULL;
        next[1] = NULL;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        
        int num2 = 0, max_xor = 0, n = nums.size();
        
        TrieNode * root = new TrieNode();
        TrieNode * curr = root;
        
        vector<vector<bool>> bin(n);
        int temp;
        for(int t = 0; t<n; t++){
            temp = nums[t];
            for(int i = 0; i<31; i++){
                bin[t].push_back(temp%2);
                temp /= 2;
            }
            reverse(bin[t].begin(), bin[t].end());
        }
        
        // insert in the Trie
        
        for(int t = 0; t<n; t++){
            curr = root;
            for(int i = 0; i<31; i++){
                if(curr->next[bin[t][i]] == NULL)
                    curr->next[bin[t][i]] = new TrieNode();
                curr = curr->next[bin[t][i]];
            }
        }
        
        // search bitwise not in the Trie
        // if bit not present, go to the other bit
        
        vector<bool> ans;
        for(int t = 0; t<n; t++){
            ans.clear();
            curr = root;
            
            for(int i = 0; i<31; i++){
                if(curr->next[!bin[t][i]] == NULL){
                    curr = curr->next[bin[t][i]];
                    ans.push_back(bin[t][i]);
                } else{
                    curr = curr->next[!bin[t][i]];
                    ans.push_back(!bin[t][i]);   
                }
            }
            
            num2 = 0;
            
            for(int i = 0; i<31; i++){
                num2 += (ans[i]*(1<<(31-i-1)));
            }
            
            max_xor = max(max_xor, (nums[t]^num2));
        }
        
        return max_xor;
    }
};