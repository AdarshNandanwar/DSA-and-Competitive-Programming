// https://leetcode.com/problems/push-dominoes/

// Method 1 (Multi Source BFS, O(n)):

class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length();
        string state(n, '.');
        vector<bool> leftForce(n, false), rightForce(n, false);
        queue<int> q;
        for(int i=0; i<n; i++){
            if(dominoes[i] == 'L'){
                state[i] = 'L';
                int nbr = i-1;
                if(nbr >= 0){
                    leftForce[nbr] = true;
                    q.push(nbr);
                }
            } else if(dominoes[i] == 'R'){
                state[i] = 'R';
                int nbr = i+1;
                if(nbr < n){
                    rightForce[nbr] = true;
                    q.push(nbr);
                }
            }
        }
        while(!q.empty()){
            int sz = q.size();
            unordered_set<int> newLeftForce, newRightForce;
            while(sz--){
                int pos = q.front();
                q.pop();
                if(state[pos] != '.'){
                    continue;
                }
                if(leftForce[pos] ^ rightForce[pos]){
                    if(leftForce[pos]){
                        state[pos] = 'L';
                        int nbr = pos-1;
                        if(nbr >= 0){
                            newLeftForce.insert(nbr);
                            q.push(nbr);
                        }
                    } else {
                        state[pos] = 'R';
                        int nbr = pos+1;
                        if(nbr < n){
                            newRightForce.insert(nbr);
                            q.push(nbr);
                        }
                    }
                }
            }
            for(auto &i:newLeftForce){
                leftForce[i] = true;
            }
            for(auto &i:newRightForce){
                rightForce[i] = true;
            }
        }
        return state;
    }
};