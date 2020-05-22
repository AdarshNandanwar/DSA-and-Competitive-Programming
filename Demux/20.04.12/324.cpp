// https://leetcode.com/problems/wiggle-sort-ii/

// Method 1 (O(n)):

class Solution {
public:
    
    int mapping(int n, int i){
        
        // Putting medians in the opposite ends
        // Reversing to avoid [4,5,5,6] case
        
        // odd          --->         8 7 6 5        --->
        // 012345678    --->        4 3 2 1 0       --->    483726150
        
        // even         --->         7 6 5 4        --->
        // 01234567     --->        3 2 1 0         --->    37261504
        
        int m = (n+1)/2;
        if(i<m){
            return 2*(m-i-1);
        } else {
            if(n%2){
                return (n-2*(i-m+1));
            } else {
                return (n-2*(i-m+1)+1);
            }
        }
    }
    
    void wiggleSort(vector<int>& nums) {
        
        int n = nums.size();
        if(n==1) return;
        
        auto mid = nums.begin() + (n+1)/2;
        
        // Places the ele at midth ele in sorted array in nums[mid] and
        // for all i<mid, nums[i] <= nums[mid] and for all i>mid, nums[i]>=nums[mid]
        
        nth_element(nums.begin(), mid, nums.end());
        int m = *mid;
        
        // Partition array into:   [lower][equal_to_median][higher]
        // i.e. sticks the median together
        
        // int i = 0, j = 0, k = n-1;
        // while(j<=k){
        //     if(nums[j] < m){
        //         swap(nums[i++], nums[j++]);
        //     } else if(nums[j] > m){
        //         swap(nums[k--], nums[j]);
        //     } else {
        //         j++;
        //     }
        // }
        
        
        // Remapping the array
        
        int i = 0, j = 0, k = n-1;
        while(j<=k){
            if(nums[mapping(n, j)] < m){
                swap(nums[mapping(n, i++)], nums[mapping(n, j++)]);
            } else if(nums[mapping(n, j)] > m){
                swap(nums[mapping(n, k--)], nums[mapping(n, j)]);
            } else {
                j++;
            }
        }
        
    }
};

// Method 2 (Sorting O(nlogn)):

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> v(n);
        int mid = (n+1)/2;
        for(int i = 0; i<mid; i++){
            v[(mid-i-1)*2] = nums[i];
        }
        for(int i = mid; i<n; i++){
            v[2*(n-i)-1] = nums[i];
        }
        for(int i =0; i<n; i++){
            nums[i] = v[i];
        }
    } 
};