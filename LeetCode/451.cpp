// https://leetcode.com/problems/sort-characters-by-frequency/

// Method 1 (Hash map, O(nlogn)):

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