// https://leetcode.com/problems/remove-all-occurrences-of-a-substring/

// Method 1 (Stack, O(n*m)):

class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = s.length();
        int m = part.length();

        stack<char> st;
        for(int i=0; i<n; i++){
            st.push(s[i]);
            if(st.size() >= m){
                stack<char> temp;
                int index = m-1;
                while(index >= 0){
                    if(st.top() != part[index]){
                        break;
                    }
                    temp.push(st.top());
                    st.pop();
                    index--;
                }
                if(index >= 0){
                    while(!temp.empty()){
                        st.push(temp.top());
                        temp.pop();
                    }
                }
            }
        }

        string res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};