// https://leetcode.com/problems/maximum-distance-in-arrays/

// Method 1 (1 Loop, O(n) time, O(1) space):

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int m = arrays.size();
        int prevHighest = -1e4, prevLowest = 1e4;
        int distance = INT_MIN;
        for(int i=0; i<m; i++){
            int highest = arrays[i].back();
            int lowest = arrays[i].front();

            distance = max(distance, prevHighest - arrays[i].front());
            distance = max(distance, arrays[i].back() - prevLowest);

            prevHighest = max(prevHighest, highest);
            prevLowest = min(prevLowest, lowest);
        }

        return distance;
    }
};

// Method 2 (2 Loops, O(n) time, O(1) space):

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int highest1 = INT_MIN, highest2 = INT_MIN;
        int lowest1 = INT_MAX, lowest2 = INT_MAX;
        int m = arrays.size();
        for(int i=0; i<m; i++){
            int highest = arrays[i].back();
            int lowest = arrays[i].front();

            if(highest > highest1){
                highest2 = highest1;
                highest1 = highest;
            } else if(highest > highest2){
                highest2 = highest;
            }

            if(lowest < lowest1){
                lowest2 = lowest1;
                lowest1 = lowest;
            } else if(lowest < lowest2){
                lowest2 = lowest;
            }
        }

        int distance = INT_MIN;
        for(int i=0; i<m; i++){
            if(arrays[i].back() == highest1){
                distance = max(distance, highest2 - arrays[i].front());
            } else {
                distance = max(distance, highest1 - arrays[i].front());
            }
            if(arrays[i].front() == lowest1){
                distance = max(distance, arrays[i].back() - lowest2);
            } else {
                distance = max(distance, arrays[i].back() - lowest1);
            }
        }

        return distance;
    }
};
