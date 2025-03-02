// https://leetcode.com/problems/walking-robot-simulation/

// Method 1 (Brute Force, O(n+m)):

class Solution {
    vector<int> dirs = {0, -1, 0, 1, 0};
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_map<int, unordered_set<int>> obstacleSets;
        for(auto obstacle:obstacles){
            obstacleSets[obstacle[0]].insert(obstacle[1]);
        }

        int x = 0, y = 0;
        int dir = 2;
        int maxDist = 0;

        for(auto command:commands){
            if(command >= 1){
                while(command--){
                    x += dirs[dir];
                    y += dirs[dir+1];
                    if(obstacleSets.count(x) and obstacleSets[x].count(y)){
                        x -= dirs[dir];
                        y -= dirs[dir+1];
                        break;
                    }
                }
            } else if(command == -1){
                dir = (dir + 1) % 4;
            } else if(command == -2){
                dir = (dir + 3) % 4;
            }
            maxDist = max(maxDist, x*x + y*y);
        }

        return maxDist;
    }
};
