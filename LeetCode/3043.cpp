// https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/

// Method 1 (Trie, O(9*(n+m)) = O(n+m)):

class Solution {
    struct TrieNode {
        TrieNode * next[10];
    };
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        TrieNode * root = new TrieNode();

        for(int num:arr1){
            TrieNode * cur = root;
            for(char c:to_string(num)){
                if(cur->next[c-'0'] == nullptr){
                    cur->next[c-'0'] = new TrieNode();
                }
                cur = cur->next[c-'0'];
            }
        }

        int lcp = 0;

        for(int num:arr2){
            TrieNode * cur = root;

            int curPrefixLen = 0;
            for(char c:to_string(num)){
                if(cur->next[c-'0'] == nullptr){
                    break;
                }
                cur = cur->next[c-'0'];
                curPrefixLen++;
            }

            lcp = max(lcp, curPrefixLen);
        }


        return lcp;
    }
};
