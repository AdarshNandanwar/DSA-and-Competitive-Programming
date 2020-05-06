// https://leetcode.com/problems/custom-sort-string/

unordered_map<int, int> m;

bool isPresent(int a){
    if(m.find(a) == m.end()) return false;
    return true;
}

bool comp(char a, char b){
    if(isPresent(a) && isPresent(b)){
        return m[a] < m[b];
    } else if(isPresent(a)){
        return true;
    } else if(isPresent(b)){
        return false;
    } else {
        return a<b;
    }
}

class Solution {
public:
    string customSortString(string S, string T) {
        m.clear();
        for(int i = 0; i<S.size(); i++){
            m[S[i]] = i;
        }
        sort(T.begin(), T.end(), comp);
        return T;    
    }
};