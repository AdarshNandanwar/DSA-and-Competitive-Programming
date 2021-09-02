// https://leetcode.com/problems/two-sum/

// Method 1 (hashing, O(n)):

class Solution {
public:
    vector<int> twoSum(vector<int>& A, int target) {
        unordered_map<int, int> m;
        for(int i = 0; i<A.size(); i++){
            if(m.count(target-A[i])) return {m[target-A[i]], i};
            m[A[i]] = i;
        }
        return {0,0};
    }
};

// Method 2 (sort, 2 pointer, O(nlogn)):

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> v;
        for(int i = 0; i<n; i++) v.push_back({nums[i], i});
        sort(v.begin(), v.end());
        int p1 = 0, p2 = n-1;
        while(p1<p2){
            if(v[p1][0]+v[p2][0] > target) p2--;
            else if(v[p1][0]+v[p2][0] < target) p1++;
            else return {v[p1][1], v[p2][1]};
        }
        return {0,0};
    }
};

// Method 3 (O(n2)):

class Solution {
public:
    vector<int> twoSum(vector<int>& A, int target) {
        for(int i = 0; i<A.size(); i++){
            for(int j = i+1; j<A.size(); j++){
                if(A[i]+A[j] == target) return {i,j};
            }
        }
        return {};
    }
};