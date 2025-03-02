// https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/

// Method 1 (Hash Map, O(n)):

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();

        int totalSkill = 0;
        unordered_map<int, int> freq;
        for(int s:skill){
            totalSkill += s;
            freq[s]++;
        }

        if(totalSkill % (n/2) != 0){
            return -1;
        }

        long long chemistry = 0; 
        int targetSkill = totalSkill / (n / 2);
        for(int s:skill){

            int teammateSkill = targetSkill - s;
            if(freq.count(teammateSkill) == 0 or freq[s] != freq[teammateSkill]){
                return -1;
            }

            chemistry += (s*teammateSkill);
        }

        return chemistry / 2;
    }
};
