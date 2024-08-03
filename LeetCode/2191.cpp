// https://leetcode.com/problems/sort-the-jumbled-numbers/

// Method 1 (Sorting, O(nlogn)):

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> data(n, vector<int>(2));
        for(int i=0; i<n; i++){
            string input = to_string(nums[i]);
            int m = input.size();
            string output = input;
            for(int j=0; j<m; j++){
                output[j] = mapping[input[j]-'0']+'0';
            }
            data[i][0] = stoi(output);
            data[i][1] = i;
        }

        sort(data.begin(), data.end());

        vector<int> ans(n);
        for(int i=0; i<n; i++){
            ans[i] = nums[data[i][1]];
        }
        
        return ans;
    }
};
