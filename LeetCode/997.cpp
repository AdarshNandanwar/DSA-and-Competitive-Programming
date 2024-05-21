// https://leetcode.com/problems/find-the-town-judge/

// Method 1 (Hash Table, O(n)):

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_set<int> notJudge;
        unordered_map<int, int> trustCount;
        for(const auto& t:trust){
            notJudge.insert(t[0]);
            trustCount[t[1]]++;
        }
        for(int i=1; i<=n; i++){
            if(notJudge.count(i)){
                continue;
            }
            if(trustCount[i] == n-1){
                return i;
            }
        }
        return -1;
    }
};