// https://leetcode.com/problems/sort-characters-by-frequency/

// Method 1 (Priority Queue, O(n+26logn)=O(n) time and O(128)=O(1) space):

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for(auto &c:s) freq[c]++;
        priority_queue<pair<int, char>, vector<pair<int, char>>> pq;
        for(auto &i:freq) pq.push({i.second, i.first});
        string ans;
        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();
            ans += string(cur.first, cur.second);
        }
        return ans;
    }
};

// Method 2 (Bucket Sort, O(n) time and O(n) space):

class Solution {
public:
    string frequencySort(string s) {
        // Bucket Sort
        int n = s.length();
        vector<int> freq(128, 0);
        for(auto &c:s) freq[c]++;
        unordered_map<int, unordered_set<int>> rev_freq;
        for(auto &c:s) rev_freq[freq[c]].insert(c);
        string ans;
        for(int i=n; i>=0; i--){
            for(auto &j:rev_freq[i]){
                ans += string(i, j);
            }
        }
        return ans;
    }
};

// Method 3 (Hash map, O(nlogn)):

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<int, int> m;
        for(auto &i:s) m[i]++;
        sort(s.begin(), s.end(), [&m](const char & a, const char & b){
            return m[a] == m[b] ? a<b : m[a] > m[b];
        });
        return s;
    }
};

// Alternate Code (array, long version, O(nlogn)):

class Solution {
public:
    string frequencySort(string s) {
        vector<int> freq(128, 0);
        for(auto c:s) freq[c]++;
        vector<char> order(128);
        for(int i=0; i<128; i++) order[i] = i;
        sort(order.begin(), order.end(), [&freq](const char & a, const char & b){return freq[a] > freq[b];});
        string res;
        for(int i = 0; i<128; i++) res += string(freq[order[i]], order[i]);
        return res;
    }
};