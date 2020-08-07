// https://leetcode.com/problems/substring-with-concatenation-of-all-words/

// Method 1 (Two pointer):

class Solution {
public:
    
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.length(), wn = words.size(), remaining;
        vector<int> res;
        if(wn == 0 or wn*words[0].length()>n) return res;
        int ws = words[0].length();
        
        unordered_map<string, int> freq_m;
        
        string sub, stSub;
        int p1, p2;
        // [p1, p2)
        
        for(int i = 0; i<ws; i++){
            freq_m.clear();
            for(auto w:words) freq_m[w]--;
            remaining = wn;
            p1 = p2 = i;
            while(p2<n){
                p2 += ws;
                sub = s.substr(p2-ws, ws);
                // cout<<"checking: "<<sub<<endl;
                if(freq_m.find(sub) == freq_m.end()){
                    while(p1 < p2-ws){
                        stSub = s.substr(p1, ws);
                        // cout<<"removing: "<<stSub<<endl;
                        freq_m[stSub]--;
                        remaining++;
                        p1 += ws;
                    }
                    p1 = p2 = p1+ws;
                } else {
                    while(freq_m[sub] >= 0){
                        stSub = s.substr(p1, ws);
                        // cout<<"removing: "<<stSub<<endl;
                        freq_m[stSub]--;
                        remaining++;
                        p1 += ws;
                    }
                    // cout<<"adding: "<<sub<<endl;
                    freq_m[sub]++;
                    remaining--;
                }
                // cout<<"remaining: "<<remaining<<endl;
                if(remaining == 0){
                    res.push_back(p1);
                    for(auto w:words) freq_m[w]--;
                    remaining = wn;
                    p1 = p2 = p1+ws;
                }
            }
        }
        
        return res;
    }
};

// Method 1 (Two pointer, Alternate Code):

class Solution {
public:
    void helper(string & s, const vector<string> & words, int start, vector<int> & ans, unordered_map<string, int> & freq){
        int n = s.length(), len = words[0].length(), remaining = words.size();
        // [p1, p2)
        int p1 = start, p2 = start;
        while(p2+len-1<n){
            while(p2+len-1<n and !freq.count(s.substr(p2, len))){
                while(p1<p2){
                    if(freq.count(s.substr(p1, len))) freq[s.substr(p1, len)]--;
                    remaining++;
                    p1 += len;
                }
                p1 = p2 = p2+len;
            } 
            while(p1<p2 and p2+len-1<n and freq[s.substr(p2, len)] == 0){
                freq[s.substr(p1, len)]--;
                remaining++;
                p1 += len;
            }
            if(p2+len-1<n){
                freq[s.substr(p2, len)]++;
                remaining--;
                p2 += len;
                if(remaining == 0){
                    ans.push_back(p1);
                }
            }
        }
        while(p1<p2){
            if(freq.count(s.substr(p1, len))) freq[s.substr(p1, len)]--;
            p1 += len;
        }
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.length(), m = words.size();
        vector<int> ans;
        if(m == 0) return ans;
        int len = words[0].length();

        unordered_map<string, int> freq;
        for(auto s:words) freq[s]--;

        for(int i = 0; i<len; i++) helper(s, words, i, ans, freq);

        return ans;
    }
};

// Method 2 (172/173 passed):
// This method works also when the words are of different lengths

class Solution {
public:
    
    bool findSubstringHelper(string s, int index, int remaining, int & wl,  unordered_map<int, unordered_set<string>> & ind_m, unordered_map<string, int> & freq_m, vector<int> & res){
        int n = s.length();
        
        if(remaining == 0){ 
            res.push_back(index-wl);
            return true;
        }
        
        if(index >= n) return false;
            
        bool found = false;
        
        for(auto word:ind_m[index]){
            if(!freq_m[word]) continue;
            freq_m[word]--;
            found = findSubstringHelper(s, index+word.length(), remaining-1, wl, ind_m, freq_m, res);
            freq_m[word]++;
            if(found) break;
        }
        return found;
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.length(), wl = 0;
        vector<int> res;
        unordered_map<int, unordered_set<string>> ind_m;
        unordered_map<string, int> freq_m;
        for(auto w:words){
            wl += w.length();
            freq_m[w]++;
            if(freq_m[w] > 1) continue;
            for(int i = 0; i<n; i++){
                int j;
                for(j = 0; j<w.length(); j++){
                    if(i+j>=n or s[i+j] != w[j]) break;
                }
                if(j == w.length()) ind_m[i].insert(w);
            }
        }
        
        if(wl > n) return res;
        
        vector<int> start_index;
        for(auto ind:ind_m) start_index.push_back(ind.first);
        
        for(auto ind:start_index){
            findSubstringHelper(s, ind, words.size(), wl, ind_m, freq_m, res);
        }
        
        return res;
    }
};