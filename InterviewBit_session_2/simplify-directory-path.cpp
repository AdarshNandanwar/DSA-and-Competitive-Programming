// https://www.interviewbit.com/problems/simplify-directory-path/

string Solution::simplifyPath(string A) {
    istringstream iss(A);
    string s;
    stack<string> st, temp;
    while(getline(iss, s, '/')){
        if(s == "" or s == "."){
            continue;
        } else if(s == ".."){
            if(!st.empty()) st.pop();
        } else {
            st.push(s);
        }
    }
    while(!st.empty()){
        temp.push(st.top());
        st.pop();
    }
    string res = "";
    while(!temp.empty()){
        res += "/"+temp.top();
        temp.pop();
    }
    return res.length() ? res : "/";
}
