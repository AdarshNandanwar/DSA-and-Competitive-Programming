// https://leetcode.com/problems/sort-characters-by-frequency/

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