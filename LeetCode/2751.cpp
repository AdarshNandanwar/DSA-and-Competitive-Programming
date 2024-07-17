// https://leetcode.com/problems/robot-collisions/

// Method 1 (Stack + Sorting, O(nlogn) time, O(n) space):

class Solution {
    struct Robot{
        int index;
        int pos;
        int health;
        char dir;

        Robot(int index, int pos, int health, char dir): index(index), pos(pos), health(health), dir(dir) {}
    };
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();

        vector<Robot *> robots;
        for(int i=0; i<n; i++){
            robots.push_back(new Robot(i, positions[i], healths[i], directions[i]));
        }
        sort(robots.begin(), robots.end(), [](const Robot * a, const Robot * b){
            return a->pos < b->pos;
        });

        stack<Robot *> st;
        for(auto robot:robots){

            Robot * nextRobot = robot;
            bool skip = false;

            while(nextRobot->dir == 'L' and !st.empty() and st.top()->dir == 'R'){
                // RL pattern => collision
                auto prevRobot = st.top();
                st.pop();

                if(prevRobot->health < nextRobot->health){
                    nextRobot->health--;
                } else if(prevRobot->health > nextRobot->health){
                    nextRobot = prevRobot;
                    nextRobot->health--;
                } else {
                    skip = true;
                    break;
                }
            }
            
            if(!skip){
                st.push(nextRobot);
            }
        }

        robots.clear();
        while(!st.empty()){
            robots.push_back(st.top());
            st.pop();
        }
        sort(robots.begin(), robots.end(), [](const Robot * a, const Robot * b){
            return a->index < b->index;
        });
        int m = robots.size();
        vector<int> remainingHealths(m);
        for(int i=0; i<m; i++){
            remainingHealths[i] = robots[i]->health;
        }

        return remainingHealths;
    }
};
