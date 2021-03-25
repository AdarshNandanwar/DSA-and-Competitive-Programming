// https://leetcode.com/problems/simplify-path/

class Solution {
public:
    string simplifyPath(string path) {
        string ans = "";
        int l = path.length();
        stack<string> st;
        for(int i = 0; i<l; i++){
            if(path[i] == '/'){
                continue;
            }
            int start = i;
            while(i<l && path[i] != '/'){
                i++;
            }
            string t = path.substr(start, i-start);
            if(t == ".." && !st.empty()) st.pop();
            else if(t == ".." && st.empty()) continue;
            else if(t != ".") st.push(t);
        }
        while(!st.empty()){
            string t;
            t = st.top();
            st.pop();
            ans = "/"+t+ans;
        }
        if(!ans.length()) ans = "/";
        return ans;
    }
};