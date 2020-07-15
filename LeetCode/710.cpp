// https://leetcode.com/problems/random-pick-with-blacklist/

class Solution {
public:
    int N, len;
    unordered_map<int, int> m;
    
    Solution(int N, vector<int>& blacklist) {
        this->N = N;
        unordered_set<int> st;
        for(auto i:blacklist) st.insert(i);
        len = blacklist.size();
        // mapping all num in blacklist less than N-len to another number >=N-len which not in blacklist
        int p1 = 0, p2 = N-len;
        while(p1<len){
            if(blacklist[p1] < N-len){
                while(p2<N){
                    if(!st.count(p2)){
                        m[blacklist[p1++]] = p2++;
                        break;
                    } else {
                        p2++;
                    }
                }
            } else {
                p1++;
            }
        }
    }
    
    int pick() {
        int res = rand()%(N-len);
        return m.count(res)?m[res]:res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(N, blacklist);
 * int param_1 = obj->pick();
 */