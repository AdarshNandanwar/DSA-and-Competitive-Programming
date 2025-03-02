// https://leetcode.com/problems/construct-string-with-repeat-limit/

// Method 1 (Max Heap, O(nlog26) = O(n)):

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        priority_queue<pair<char, int>, vector<pair<char, int>>> pq;
        unordered_map<char, int> freq;
        for(char c:s){
            freq[c]++;
        }
        for(auto f:freq){
            pq.push(f);
        }

        if(pq.empty()){
            return "";
        }

        string res;
        auto cur = pq.top();
        pq.pop();
        while(!pq.empty()) {
            auto next = pq.top();
            pq.pop();

            int repeatCount;
            if(cur.first < next.first){
                repeatCount = 1;
            } else {
                repeatCount = min(repeatLimit, cur.second);
            }
            res += string(repeatCount, cur.first);
            cur.second -= repeatCount;

            if(cur.second){
                pq.push(cur);
            }
            cur = next;
        }

        int repeatCount = min(repeatLimit, cur.second);
        res += string(repeatCount, cur.first);

        return res;
    }
};
