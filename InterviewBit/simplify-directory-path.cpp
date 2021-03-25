// https://www.interviewbit.com/problems/simplify-directory-path/

// Method 1 (Input strign stream, Stack, O(n)):

string Solution::simplifyPath(string A) {
    istringstream iss(A);
    string w, res = "";
    stack<string> st, rev;
    while(getline(iss, w, '/')){
        if(w == ".") continue;
        else if(w == ".."){
            if(!st.empty()) st.pop();
        } else st.push(w);
    }
    while(!st.empty()){
        rev.push(st.top());
        st.pop();
    }
    while(!rev.empty()){
        if(rev.top().length()) res += ("/"+rev.top());
        rev.pop();
    }
    return res.length() ? res : "/";
}
