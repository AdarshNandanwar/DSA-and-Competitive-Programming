// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/

// Method 1 (Stack, O(n)):

class Solution {
public:
    string removeDuplicates(string s, int k) {
        // {char, suffixFreq}
        stack<pair<char, int>> st;
        int n=s.length();
        for(int i=0; i<n; i++){
            if(st.empty()){
                st.push(make_pair(s[i], 1));
            } else {
                auto prev = st.top();
                char prevChar = prev.first;
                int prevFreq = prev.second;
                if(prevChar == s[i]){
                    st.push(make_pair(s[i], prevFreq+1));
                    if(prevFreq+1 == k){
                        for(int j=0; j<k; j++){
                            st.pop();
                        }
                    }
                } else {
                    st.push(make_pair(s[i], 1));
                }
            }
        }
        string res = "";
        while(!st.empty()){
            res.push_back(st.top().first);
            st.pop();
        }
        return string(res.rbegin(), res.rend());
    }
};

// Alternate Code:

class Solution {
public:
    string removeDuplicates(string s, int k) {
        // {char, longest occurence of this char}
        stack<pair<char, int>> st;
        for(int i = 0; i<s.length(); i++){
            if(st.empty()){
                st.push(make_pair(s[i], 1));
                continue;
            }
            st.push(make_pair(s[i], (st.top().first == s[i] ? st.top().second+1 : 1)));
            if(st.top().second == k){
                for(int j = 0; j<k; j++) st.pop();
            }
        }
        string res;
        while(!st.empty()){
            res.push_back(st.top().first); 
            st.pop();
        } 
        reverse(res.begin(), res.end());
        return res;
    }
};