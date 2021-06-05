// https://leetcode.com/problems/search-suggestions-system/

// Method 1 (Sort, Binary Search):

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> res = {};
        sort(products.begin(), products.end());
        string cur = "";
        for(auto &c:searchWord){
            cur += c;
            int start = lower_bound(products.begin(), products.end(), cur)-products.begin();
            vector<string> v;
            for(int i = start; i<min(start+3, (int)products.size()); i++){
                if(products[i].find(cur)>0) break;
                v.push_back(products[i]);
            }
            res.push_back(v);
        }
        return res;
    }
};

// Method 2 (Trie):

struct Trie{
    priority_queue<string, vector<string>> pq;
    bool is_word;
    Trie * next[26];
    Trie(){
        this->is_word = false;
        for(int i = 0; i<26; i++) this->next[i] = NULL;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        Trie * root = new Trie();
        
        // Add in Trie
        for(auto & p:products){
            Trie * cur = root;
            for(auto & c:p){
                if(cur->next[c-'a'] == NULL){
                    cur->next[c-'a'] = new Trie();
                }
                cur = cur->next[c-'a'];
                cur->pq.push(p);
                if(cur->pq.size()>3) cur->pq.pop();
            }
            cur->is_word = true;
        }
        
        // Search
        vector<vector<string>> res = {};
        Trie * cur = root;
        for(auto & c: searchWord){
            if(cur->next[c-'a'] == NULL){
                cur->next[c-'a'] = new Trie();
            }
            cur = cur->next[c-'a'];
            vector<string> v = {};
            while(!cur->pq.empty()){
                v.push_back(cur->pq.top());
                cur->pq.pop();
            }
            reverse(v.begin(), v.end());
            res.push_back(v);
        }
        
        return res;
    }
};