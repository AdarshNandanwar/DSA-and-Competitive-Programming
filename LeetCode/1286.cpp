// https://leetcode.com/problems/iterator-for-combination/

class CombinationIterator {
public:
    
    queue<string> q;
    
    void helper(const string & s, const int & len, int start, string cur){
        if(cur.length() == len){
            q.push(cur);
            return;
        }
        for(int i = start; i<s.length(); i++) helper(s, len, i+1, cur+s[i]);
    }
    
    CombinationIterator(string characters, int combinationLength) {
        helper(characters, combinationLength, 0 ,"");
    }
    
    string next() {
        string res = q.front();
        q.pop();
        return res;
    }
    
    bool hasNext() {
        return !q.empty();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */