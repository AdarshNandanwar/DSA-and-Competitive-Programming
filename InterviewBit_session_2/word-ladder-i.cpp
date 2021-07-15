// https://www.interviewbit.com/problems/word-ladder-i/

bool is_nbr(const string & s1,const  string & s2){
    int diff = 0;
    if(s1.length() != s2.length()) return 0;
    for(int i = 0; i<s1.length(); i++){
        if(s1[i] != s2[i]) diff++;
        if(diff>1) return 0;
    }
    return diff == 1;
}

int Solution::solve(string A, string B, vector<string> &C) {
    int res = 1;
    unordered_set<string> dict(C.begin(), C.end());
    dict.insert(B);
    queue<string> q;
    q.push(A);
    dict.erase(A);
    while(!q.empty()){
        vector<string> v;
        while(!q.empty()){
            if(q.front() == B) return res;
            v.push_back(q.front());
            q.pop();
        }
        vector<string> to_erase;
        for(auto &s:v){
            for(auto &d:dict){
                if(is_nbr(s, d)){
                    to_erase.push_back(d);
                    q.push(d);
                }
            }
        }
        for(auto &s:to_erase){
            dict.erase(s);
        }
        res++;
    }
    return 0;
}
