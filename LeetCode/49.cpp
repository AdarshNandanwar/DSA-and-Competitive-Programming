// https://leetcode.com/problems/group-anagrams/

// Method 1 (Hsh Map, Sorting, O(n*l*logl)):

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramIndexes;
        for(int i=0; i<strs.size(); i++){
            string hash = strs[i];
            sort(hash.begin(), hash.end());
            anagramIndexes[hash].push_back(strs[i]);
        }
        vector<vector<string>> anagramGroups;
        for(const auto& indexes:anagramIndexes){
            anagramGroups.push_back(indexes.second);
        }
        return anagramGroups;
    }
};

// Method 2 (Hash Map, Hash Function, O(n*l)):

class Solution {
    void getHash(const string& s, string& outHash){
        vector<int> freq(26);
        for(const char c:s){
            freq[c-'a']++;
        }
        outHash = "";
        for(const int& f:freq){
            outHash += f;
            outHash += ",";
        }
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramIndexes;
        for(int i=0; i<strs.size(); i++){
            string hash;
            getHash(strs[i], hash);
            anagramIndexes[hash].push_back(strs[i]);
        }
        vector<vector<string>> anagramGroups;
        for(const auto& indexes:anagramIndexes){
            anagramGroups.push_back(indexes.second);
        }
        return anagramGroups;
    }
};