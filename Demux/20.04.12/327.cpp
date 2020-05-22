// https://leetcode.com/problems/count-of-range-sum/

typedef long long ll;

class Solution {
public:
    
    ll merger(vector<ll> & cumSum, ll start, ll mid, ll end, ll lower, ll upper){
        ll i, j, k, n1 = 0, n2 = 0;
        
        // pairs having sum lesser than lower
        i = start; j = mid+1;
        while(i<=mid and j<=end){
            if(cumSum[j] - cumSum[i] < lower){
                n1 += (mid-i+1);
                j++;
            } else {
                i++;
            }
        }
        // pairs having sum lesser than equal to upper
        i = start; j = mid+1;
        while(i<=mid and j<=end){
            if(cumSum[j] - cumSum[i] <= upper){
                n2 += (mid-i+1);
                j++;
            } else {
                i++;
            }
        }
        
        // Merge Sort
        vector<ll> left, right;
        for(int i = start; i<=end; i++){
            if(i<=mid){
                left.push_back(cumSum[i]);
            } else {
                right.push_back(cumSum[i]);
            }
        }
        
        i = 0, j = 0, k = start;
        while(i<left.size() and j<right.size()){
            if(left[i] <= right[j]){
                cumSum[k++] = left[i++];
            } else {
                cumSum[k++] = right[j++];
            }
        }
        while(i<left.size()){
            cumSum[k++] = left[i++];
        }
        while(j<right.size()){
            cumSum[k++] = right[j++];
        }
        
        return n2-n1;
        
    }
    
    ll helper(vector<ll>& cumSum, ll start, ll end, ll lower, ll upper){
        
        if(start >= end){
            return 0;
        }
        
        ll mid = start+(end-start)/2;
        
        ll n1 = helper(cumSum, start, mid, lower, upper);
        
        ll n2 = helper(cumSum, mid+1, end, lower, upper);
        
        ll n3 = merger(cumSum, start, mid, end, lower, upper);
        
        return n1+n2+n3;
    }
    
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        
        ll n = nums.size();
        
        // cumulative sum
        vector<ll> cumSum;
        cumSum.push_back(0);
        for(ll i = 0; i<n; i++){
            cumSum.push_back(cumSum.back()+nums[i]);
        }
        
        return helper(cumSum, 0, n, lower, upper);
    }
};