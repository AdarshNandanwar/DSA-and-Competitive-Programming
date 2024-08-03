// https://leetcode.com/problems/most-profit-assigning-work/

// Method 1 (Hash Map, O(n + m + maxAbility)):

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size(), m = worker.size();
        int maxAbility = *max_element(worker.begin(), worker.end());

        vector<int> maxProfit(maxAbility+1, 0);

        for(int i=0; i<n; i++){
            if(difficulty[i] > maxAbility){
                continue;
            }
            maxProfit[difficulty[i]] = max(maxProfit[difficulty[i]], profit[i]);
        }

        // Compute prefix max
        for(int i=1; i<=maxAbility; i++){
            maxProfit[i] = max(maxProfit[i], maxProfit[i-1]);
        }

        int ans = 0;
        for(int w:worker){
            ans += maxProfit[w];
        }

        return ans;
    }
};

// Method 2 (Ordered Map, O((n+m)logn)):

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size(), m = worker.size();

        map<int, int> jobs;
        for(int i=0; i<n; i++){
            jobs[difficulty[i]] = max(jobs[difficulty[i]], profit[i]);
        }

        // Compute prefix max
        for(auto itr = jobs.begin(); itr != jobs.end(); itr++){
            if(itr == jobs.begin()){
                continue;
            }
            itr->second = max(itr->second, prev(itr)->second);
        }

        int maxProfit = 0;
        for(int w:worker){
            // Get the key that is at max worker's ability
            auto nextItr = jobs.upper_bound(w);
            if(nextItr == jobs.begin()){
                continue;
            }
            maxProfit += prev(nextItr)->second;
        }

        return maxProfit;
    }
};
