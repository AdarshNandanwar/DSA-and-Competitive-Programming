// https://leetcode.com/problems/top-k-frequent-words/

struct Comp{
    bool operator()(const pair<int, string> & a, const pair<int, string> & b) const {
        if(a.first == b.first)
            return a.second<b.second;
        else
            return a.first > b.first;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        priority_queue<pair<int, string>, vector<pair<int, string>>, Comp> q;
        int n = words.size();
        
        // O(n)
        for(auto i:words)
            freq[i]++;
        
        // O(k)
        auto it = freq.begin();
        for(int i = 0; i<k and it!=freq.end(); i++, it++)
            q.push({it->second, it->first});
        
        // O((n-k)log(k))
        while(it != freq.end()){
            if(q.top().first < it->second or (q.top().first == it->second and q.top().second > it->first)){
                q.pop();
                q.push({it->second, it->first});
            }
            it++;
        }
        
        // O(k)
        vector<string> ans;
        while(!q.empty()){
            ans.push_back(q.top().second);
            q.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};