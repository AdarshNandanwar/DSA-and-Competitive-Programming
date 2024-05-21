// https://leetcode.com/problems/boats-to-save-people/

// Method 1 (Sorting, O(nlogn)):

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n = people.size();
        int p1 = 0, p2 = n-1;
        int boats = 0;
        while(p1<p2){
            if(people[p1] + people[p2] <= limit){
                boats++;
                p1++;
                p2--;
            } else {
                boats++;
                p2--;
            }
        }
        if(p1 == p2){
            boats++;
        }
        return boats;
    }
};
