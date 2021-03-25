// https://leetcode.com/problems/reverse-pairs/

// Method 1 (O(nlogn)):

class Solution {
public: 
    
    int merge(vector<int> & nums, int lo, int mid, int hi){
        vector<int> temp;
        int i = lo, j = mid+1, index, revCount = 0, n = nums.size();
        
        for(i = lo, j = mid+1; i<=mid; i++){
            while(j<=hi and nums[i] > 2L*nums[j]){
                j++;
            }
            revCount += (j-mid-1);
        }
        
        i = lo; j = mid+1;
        
        while(i<=mid and j<=hi){
            if(nums[i] < nums[j]){
                temp.push_back(nums[i++]);
            } else {
                temp.push_back(nums[j++]);
            }
        }
        while(i<=mid){
            temp.push_back(nums[i++]);
        }
        while(j<=hi){
            temp.push_back(nums[j++]);
        }
        index = lo;
        for(auto t:temp){
            nums[index++] = t;
        }
        return revCount;
    }
    
    int mSort(vector<int> & nums, int lo, int hi){
        if(lo>=hi) return 0;
        
        int mid = lo+(hi-lo)/2, revCount = 0;
        revCount += mSort(nums, lo, mid) + mSort(nums, mid+1, hi);
        revCount += merge(nums, lo, mid, hi);
        return revCount;
    }
    
    int reversePairs(vector<int>& nums) {
        
        // Merge Sort
        int n = nums.size();
        return mSort(nums, 0, n-1);       
    }
};

// Method 2 (Merge Sort, O(n(logn)2)):

class Solution {
public: 
    
    int merge(vector<int> & nums, int lo, int mid, int hi){
        vector<int> temp;
        int i = lo, j = mid+1, index, revCount = 0;
        
        for(int i = mid+1; i<=hi; i++){
            revCount += nums.begin()+mid+1-upper_bound(nums.begin()+lo, nums.begin()+mid+1, (long long int)2*nums[i]);
        }
        
        while(i<=mid and j<=hi){
            if(nums[i] < nums[j]){
                temp.push_back(nums[i++]);
            } else {
                temp.push_back(nums[j++]);
            }
        }
        while(i<=mid){
            temp.push_back(nums[i++]);
        }
        while(j<=hi){
            temp.push_back(nums[j++]);
        }
        index = lo;
        for(auto t:temp){
            nums[index++] = t;
        }
        return revCount;
    }
    
    int mSort(vector<int> & nums, int lo, int hi){
        if(lo>=hi) return 0;
        
        int mid = lo+(hi-lo)/2, revCount = 0;
        revCount += mSort(nums, lo, mid);
        revCount += mSort(nums, mid+1, hi);
        revCount += merge(nums, lo, mid, hi);
        return revCount;
    }
    
    int reversePairs(vector<int>& nums) {
        
        // Merge Sort
        int n = nums.size();
        return mSort(nums, 0, n-1);       
    }
};

// Method 3 (O(n2)):

class Solution {
public:
        
    int reversePairs(vector<int>& nums) {
        // Merge Sort
        long long int n = nums.size(), revCount = 0;
        multiset<long long int> s;
        for(int i  =0; i<n; i++){
            revCount += distance(s.upper_bound((long long int)2*nums[i]), s.end());
            s.insert(nums[i]);
        }
        return revCount;
    }
};