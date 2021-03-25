// https://www.interviewbit.com/problems/valid-ip-addresses/

// Method 1 (Vector Recursion):

void helper(string s, int index, vector<int> & cur, vector<string> & ans){
    if(cur.size() == 4){
        if(index == s.length()){
            ans.push_back(to_string(cur[0])+"."+to_string(cur[1])+"."+to_string(cur[2])+"."+to_string(cur[3]));
        }
        return;
    }
    int n = s.length();
    
    if(s[index] == '0'){
        cur.push_back(0);
        helper(s, index+1, cur, ans);
        cur.pop_back();
    } else {
        if(index+1 <= n){
            cur.push_back(stoi(s.substr(index, 1)));
            helper(s, index+1, cur, ans);
            cur.pop_back();
        } 
        if(index+2 <= n){
            cur.push_back(stoi(s.substr(index, 2)));
            helper(s, index+2, cur, ans);
            cur.pop_back();
        } 
        if(index+3 <= n and stoi(s.substr(index, 3))<256){
            cur.push_back(stoi(s.substr(index, 3)));
            helper(s, index+3, cur, ans);
            cur.pop_back();
        } 
    }
}

vector<string> Solution::restoreIpAddresses(string A) {
    vector<string> ans;
    vector<int> cur;
    helper(A, 0, cur, ans);
    return ans;
}

// Method 2 (String Recursion):

void helper(string s, int index, int count, string cur, vector<string> & ans){
    if(count == 4){
        if(index == s.length()){
            ans.push_back(cur);
        }
        return;
    }
    int n = s.length();
    
    if(count != 0) cur.push_back('.');
    
    if(s[index] == '0'){
        helper(s, index+1, count+1, cur+"0", ans);
    } else {
        if(index+1 <= n){
            helper(s, index+1, count+1, cur+s.substr(index, 1), ans);
        } 
        if(index+2 <= n){
            helper(s, index+2, count+1, cur+s.substr(index, 2), ans);
        } 
        if(index+3 <= n and stoi(s.substr(index, 3))<256){
            helper(s, index+3, count+1, cur+s.substr(index, 3), ans);
        } 
    }
}

vector<string> Solution::restoreIpAddresses(string A) {
    vector<string> ans;
    string cur = "";
    helper(A, 0, 0, cur, ans);
    return ans;
}
