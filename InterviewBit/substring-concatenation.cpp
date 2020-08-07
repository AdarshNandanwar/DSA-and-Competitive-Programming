// https://www.interviewbit.com/problems/substring-concatenation/

void helper(string & A, const vector<string> & B, int start, vector<int> & ans, unordered_map<string, int> & freq){
    int n = A.length(), len = B[0].length(), remaining = B.size();
    // [p1, p2)
    int p1 = start, p2 = start;
    while(p2+len-1<n){
        while(p2+len-1<n and !freq.count(A.substr(p2, len))){
            while(p1<p2){
                if(freq.count(A.substr(p1, len))) freq[A.substr(p1, len)]--;
                remaining++;
                p1 += len;
            }
            p1 = p2 = p2+len;
        } 
        while(p1<p2 and p2+len-1<n and freq[A.substr(p2, len)] == 0){
            freq[A.substr(p1, len)]--;
            remaining++;
            p1 += len;
        }
        if(p2+len-1<n){
            freq[A.substr(p2, len)]++;
            remaining--;
            p2 += len;
            if(remaining == 0){
                ans.push_back(p1);
            }
        }
    }
    while(p1<p2){
        if(freq.count(A.substr(p1, len))) freq[A.substr(p1, len)]--;
        p1 += len;
    }
}

vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    int n = A.length(), m = B.size();
    vector<int> ans;
    if(m == 0) return ans;
    int len = B[0].length();
    
    unordered_map<string, int> freq;
    for(auto s:B) freq[s]--;
    
    for(int i = 0; i<len; i++) helper(A, B, i, ans, freq);
    
    return ans;
}
