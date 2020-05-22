// https://leetcode.com/problems/group-anagrams/

// Method 1

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> m;
        for(auto st:strs){
            vector<int> count(26, 0);
            for(auto ch:st){
                count[ch-'a']++;
            }
            string key = "";
            for(int i = 0; i<26; i++){
                key = key + to_string(count[i]) + ",";
            }
            m[key].push_back(st);
        }
        for(auto item:m){
            ans.push_back(item.second);
        }
        return ans;
    }
};

// Method 2 (Use Count sort to sort strign in O(k))