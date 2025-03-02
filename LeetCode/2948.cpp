// https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/

// Method 1 (Sorting + Union Find Graph, O(nlogn) time, O(n) space):

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<vector<int>> numsSorted; // {value, index}
        for(int i=0; i<n; i++){
            numsSorted.push_back({nums[i], i});
        }
        sort(numsSorted.begin(), numsSorted.end());

        unordered_map<int, vector<int>> componentValues; // Values (sorted) in a component
        vector<int> componentIds(n); // Component id of the current index in original vector
        int nComponents = 1;
        componentValues[0].push_back(numsSorted[0][0]);
        componentIds[numsSorted[0][1]] = 0;
        for(int i=1; i<n; i++){
            if(numsSorted[i][0] - numsSorted[i-1][0] > limit){
                nComponents++;
            }
            componentIds[numsSorted[i][1]] = nComponents-1;
            componentValues[nComponents-1].push_back(numsSorted[i][0]);
        }

        // Merge all component values
        vector<int> res(n);
        vector<int> componentIndex(nComponents, 0); // Pointer to the current index for every component
        for(int i=0; i<n; i++){
            int componentId = componentIds[i];
            res[i] = componentValues[componentId][componentIndex[componentId]];
            componentIndex[componentId]++;
        }
        
        return res;
    }
};
