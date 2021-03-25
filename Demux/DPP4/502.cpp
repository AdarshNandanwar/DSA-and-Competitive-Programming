// https://leetcode.com/problems/ipo/

class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        int n = Profits.size();
        vector<pair<int, int>> v(n);
        for(int i = 0; i<n; i++){
            v[i].first = Capital[i];
            v[i].second = Profits[i];
        }
        sort(v.begin(), v.end());
        priority_queue<int, vector<int>> projList;
        int index = 0;
        while(true){
            
            // adding all new options in the priority queue
            while(index<n and v[index].first<=W){
                projList.push(v[index].second);
                index++;
            }
            
            if(k == 0 or projList.empty()){
                return W;
            } else {
                W += projList.top();
                projList.pop();
                k--;
            }
        }
    }
};