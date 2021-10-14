// https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/

// Solution: https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/discuss/478708/RZ-Summary-of-all-the-solutions-I-have-learned-from-Discuss-in-Python

// Method 1 (Monotonic Stack, O(n)):

class Solution {
public:
    
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size(), res = 0;;
        stack<int> st;
        st.push(INT_MAX);
        
        for(int i = 0; i<n; i++){
            while(st.top()<arr[i]){
                int t = st.top();
                st.pop();
                res += (t*min(st.top(), arr[i]));
            }
            st.push(arr[i]);
        }
        while(st.size() > 2){
            int t = st.top();
            st.pop();
            res += (t*st.top());
        }
        return res;        
    }
};

// Method 2 (Greedy, O(n2)):

class Solution {
public:
    
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size(), minVal, minInd, adjInd, i1, i2, res = 0;;
        
        while(arr.size() > 1){
            // finding index of min element and index of min of its neighbours
            minInd = min_element(arr.begin(), arr.end())-arr.begin();
            minVal = arr[minInd];
            i1 = minInd-1>=0?arr[minInd-1]:INT_MAX;
            i2 = minInd+1<arr.size()?arr[minInd+1]:INT_MAX;
            adjInd = i1<i2?minInd-1:minInd+1;
            
            // replacing the pair with the max of the 2 element
            // adding the value of the parent node (prod of the 2 child)
            res += arr[minInd]*arr[adjInd];
            arr[minInd] = max(arr[minInd], arr[adjInd]);
            arr.erase(next(arr.begin(), adjInd));
        }
        
        return res;        
    }
};

// Method 3 (Tree, Recursion, O(n3));

class Solution {
public:
    
    pair<int, int> helper(vector<int>& arr, int i, int j, vector<vector<pair<int, int>>> & dp){
        int n = arr.size();
        if(i-j == 0) return {0, arr[i]};
        
        if(dp[i][j].first != -1) return dp[i][j];
        
        int minSum = INT_MAX;
        pair<int, int> res;
        
        // k = starting index of second subtree
        for(int k = i+1; k<=j; k++){
            auto r1 = helper(arr, i, k-1, dp);
            auto r2 = helper(arr, k, j, dp);
            if(minSum > r1.first+r2.first){
                minSum = r1.first+r2.first;
                res = {r1.second*r2.second+r1.first+r2.first, max(r1.second, r2.second)};
            }
        }
        return dp[i][j] = res;
    }
    
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {-1,-1}));
        return helper(arr, 0, n-1, dp).first;
    }
};