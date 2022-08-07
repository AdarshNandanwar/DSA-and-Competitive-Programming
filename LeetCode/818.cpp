// https://leetcode.com/problems/race-car/

// Method 1 (BFS with tree pruning, O(2^n)):

class Solution {
    string getKey(const vector<int> & v){
        return to_string(v[0])+"#"+to_string(v[1]);
    }
public:
    int racecar(int target) {
        unordered_set<string> visited;
        queue<vector<int>> q;
        vector<int> start = {0, 1};
        q.push({0, 1});
        visited.insert(getKey(start));
        int operationCount = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto cur = q.front();
                q.pop();
                int pos = cur[0];
                int speed = cur[1];
                
                if(pos == target){
                    return operationCount;
                }
                
                int posA = pos+speed;
                int speedA = 2*speed;
                vector<int> nextA = {posA, speedA};
                string keyA = getKey(nextA);
                
                int posB = pos;
                int speedB = speed>0 ? -1 : 1;
                vector<int> nextB = {posB, speedB};
                string keyB = getKey(nextB);
                
                // Pruning the tree
                if(0<=posA and posA<2*target and visited.count(keyA) == 0){
                    q.push(nextA);
                    visited.insert(keyA);
                }
                if(0<=posB and posB<2*target and visited.count(keyB) == 0){
                    q.push(nextB);
                    visited.insert(keyB);
                }
            }
            operationCount++;
        }
        return -1;
    }
};