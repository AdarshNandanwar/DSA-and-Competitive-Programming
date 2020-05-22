// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/

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