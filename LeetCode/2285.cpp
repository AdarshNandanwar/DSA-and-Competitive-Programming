// https://leetcode.com/problems/maximum-total-importance-of-roads/

// Method 1 (Degree, O(vlogv + e)):

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);
        for(auto edge:roads){
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        sort(degree.begin(), degree.end());

        long long importanceSum = 0;
        for(int i=0; i<n; i++){
            importanceSum += ((i+1ll) * degree[i]);
        }
        
        return importanceSum;
    }
};

// Alternate Code

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);
        for(auto edge:roads){
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        
        vector<vector<int>> degreeIndexPairs(n);
        for(int i=0; i<n; i++){
            degreeIndexPairs[i] = {degree[i], i};
        }

        sort(degreeIndexPairs.begin(), degreeIndexPairs.end());

        vector<int> values(n, 0);
        for(int i=0; i<n; i++){
            values[degreeIndexPairs[i][1]] = i+1;
        }

        long long importanceSum = 0;
        for(auto edge:roads){
            importanceSum += (values[edge[0]] + values[edge[1]]);
        }
        
        return importanceSum;
    }
};
