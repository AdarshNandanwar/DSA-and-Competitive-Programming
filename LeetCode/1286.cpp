// https://leetcode.com/problems/iterator-for-combination/

// Method 1 (On the fly generation, initaliaztaion O(k), next O(k)):

class CombinationIterator {
public:
    stack<int> st;
    string characters;
    int combinationLength;
    bool is_first;
    
    CombinationIterator(string characters, int combinationLength) {
        for(int i = 0; i<combinationLength; i++) st.push(i);
        this->characters = characters;
        this->combinationLength = combinationLength;
        this->is_first = true;
    }
    
    string next() {
        if(!is_first){
            // next string
            int prev = characters.length();
            while(!st.empty()){
                int cur = st.top();
                st.pop();
                if(prev-cur > 1){
                    st.push(cur+1);
                    break;
                }
                prev = cur;
            }
            // if st is empty, next is not possible
            while(st.size()<combinationLength) st.push(st.top()+1);
        }
        is_first = false;
        return get_stack_string();
    }
    
    bool hasNext() {
        stack<int> temp = st;
        int prev = characters.length();
        while(!temp.empty()){
            int cur = temp.top();
            temp.pop();
            if(prev-cur > 1){
                temp.push(cur+1);
                break;
            }
            prev = cur;
        }
        return temp.size();
    }
    
    string get_stack_string(){
        string res;
        stack<int> temp;
        while(!st.empty()){
            temp.push(st.top());
            st.pop();
        }
        while(!temp.empty()){
            st.push(temp.top());
            res.push_back(characters[temp.top()]);
            temp.pop();
        }
        return res;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

// Method 2 (Pre processing, initaliaztaion O(k!), next O(1)):

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