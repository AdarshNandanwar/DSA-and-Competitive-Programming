// https://leetcode.com/problems/design-search-autocomplete-system/

struct Comp{
    bool operator()(const pair<int, string> & a, const pair<int, string> & b) const{
        if(a.first != b.first)
            return a.first>b.first;
        else
            return a.second<b.second;
    }
};

struct Node {
    int cnt;
    set<pair<int, string>, Comp> st;
    Node * next[27];
    Node(){
        cnt = 0;
        st.clear();
        for(int i =0; i<27; i++){
            next[i] = NULL;
        }
    }
};

class AutocompleteSystem {
public:
    
    Node * curr;
    Node dummy;
    string currStr;
    
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
    
        curr = &dummy;  // dummy
        currStr = "";
            
        int n = sentences.size();
        for(int i = 0; i<n; i++){
            insert(sentences[i], times[i], false);
        }
        
    }
    
    void insert(string & s, int freq, bool exists){
        curr = &dummy;
        
        int n = s.length();
        for(int i =0 ; i<n; i++){
            if(s[i] == ' '){
                if(curr->next[26] == NULL)
                    curr->next[26] = new Node();
                curr = curr->next[26];
            }else{ 
                if(curr->next[s[i]-'a'] == NULL)
                    curr->next[s[i]-'a'] = new Node();
                curr = curr->next[s[i]-'a'];
            }
            
            if(exists){
                curr->st.erase({freq, s});
                curr->st.insert({freq+1, s});
            }else{
                curr->st.insert({freq, s});
            }
        }
        
        if(exists)
            curr->cnt = freq+1;
        else
            curr->cnt = freq;
        
        curr = &dummy;
    }    
    
    vector<string> input(char c) {
        
        vector<string> v;
        if(c == '#'){
            
            // add currStr in the Trie
            if(curr->cnt == 0)
                insert(currStr, 1, false);
            else
                insert(currStr, curr->cnt, true);
            
            currStr = "";
            return v;
        } else if(c == ' '){
            if(curr->next[26] == NULL)
                curr->next[26] = new Node();
            curr = curr->next[26];
        } else {
            if(curr->next[c-'a'] == NULL)
                curr->next[c-'a'] = new Node();
            curr = curr->next[c-'a'];
        }
        currStr += c;
        
        int i = 0;
        for(auto itr = curr->st.begin(); i<3 and itr != curr->st.end(); i++, itr++)
            v.push_back(itr->second);
        
        return v;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */