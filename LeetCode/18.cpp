// https://leetcode.com/problems/4sum/

// Method 2 (Recursion, 2 Pointers, O(n3)):

class Solution {
public:
    
    void kSum(vector<int>& nums, int start, int target, int k, vector<int> & cur, vector<vector<int>> & ans){
        if(k <= 0) return;
        if(k == 1) {
            if(count(nums.begin()+start, nums.end(), target)){
                cur.push_back(target);
                ans.push_back(cur);
                cur.pop_back();
            }
            return;
        }
        
        int n = nums.size();
        if(k==2){
            
            // 2 pointer
            
            int p1 = start, p2 = n-1;
            while(p1<p2){
                if(nums[p1]+nums[p2] > target){
                    p2--;
                } else if(nums[p1]+nums[p2] < target){
                    p1++;
                } else {
                    cur.push_back(nums[p1]);
                    cur.push_back(nums[p2]);
                    ans.push_back(cur);
                    cur.pop_back();
                    cur.pop_back();
                    p1++;
                    while(p1<p2 and nums[p1-1] == nums[p1]) p1++;
                }
            }
            
        } else {
            for(int i = start; i<n;){
                cur.push_back(nums[i]);
                kSum(nums, i+1, target-nums[i], k-1, cur, ans);
                cur.pop_back();
                i++;
                while(i<n and nums[i-1] == nums[i]) i++;
            }
        }
    }
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<int> cur;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        kSum(nums, 0, target, 4, cur, ans);
        return ans;
    }
};

// Method 2 (Hash table, O(n3)):

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > res;
        long n = nums.size();
        sort(nums.begin(), nums.end());
        unordered_set<long> s;
        unordered_set<string> done;
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                for(int k = j+1; k<n; k++){
                    if(s.count(target-nums[i]-nums[j]-nums[k])){
                        string key = to_string(nums[i])+"/"+to_string(nums[j])+"/"+to_string(nums[k]);
                        if(!done.count(key)){
                            res.push_back({target-nums[i]-nums[j]-nums[k], nums[i], nums[j], nums[k]});
                            done.insert(key);
                        }
                    }
                }
            }
            s.insert(nums[i]);
        }
        sort(res.begin(), res.end());
        return res;
    }
};