// https://leetcode.com/problems/count-of-range-sum/

// Method 1 (Prefix sum, Merge Sort 1 time, O(nlogn)):

typedef long long int ll;

class Solution {
public:
    
    ll merge(vector<ll> & v, ll lo, ll mid, ll hi, const ll lower, const ll upper){
        ll p1, p2, c1 = 0, c2 = 0;
        
        // count sum ranges <= upper
        p1 = lo, p2 = mid+1;
        while(p1<=mid and p2<=hi){
            if(v[p2]-v[p1]>upper){
                p1++;
            } else {
                c1 += (mid-p1+1);
                p2++;
            }
        }
        // count sum ranges < lower
        p1 = lo, p2 = mid+1;
        while(p1<=mid and p2<=hi){
            if(v[p2]-v[p1]>=lower){
                p1++;
            } else {
                c2 += (mid-p1+1);
                p2++;
            }
        }
        
        // merge sort
        p1 = lo; p2 = mid+1;
        vector<ll> temp;
        while(p1<=mid and p2<=hi){
            if(v[p1] <= v[p2]){
                temp.push_back(v[p1++]);
            } else {
                temp.push_back(v[p2++]);
            }
        }
        while(p1<=mid){
            temp.push_back(v[p1++]);
        }
        while(p2<=hi){
            temp.push_back(v[p2++]);
        }
        for(ll i=lo; i<=hi; i++){
            v[i] = temp[i-lo];
        }
        
        return c1-c2;
    }
    
    ll countSumInRange(vector<ll> & v, ll lo, ll hi, const ll lower, const ll upper){
        if(lo >= hi) return 0;
        ll mid = lo+(hi-lo)/2, res = 0;
        res += countSumInRange(v, lo, mid, lower, upper);
        res += countSumInRange(v, mid+1, hi, lower, upper);
        res += merge(v, lo, mid, hi, lower, upper);
        return res;
    }
    
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        ll n = nums.size(), c1, c2;
        vector<ll> prefix(n+1, 0);
        // prefix[i] = sum of first i elements i.e. nums[0, i)
        for(ll i = 0; i<n; i++) prefix[i+1] = prefix[i]+nums[i];
        return countSumInRange(prefix, 0, prefix.size()-1, lower, upper);
    }
};

// Method 2 (Prefix sum, Merge Sort 2 times, O(2*nlogn)):

class Solution {
public:
    
    long merge(vector<long> & v, int lo, int mid, int hi, const int maxSum){
        int p1 = lo, p2 = mid+1, res = 0;
        
        // count sum ranges <= maxSum
        while(p1<=mid and p2<=hi){
            if(v[p2]-v[p1]>maxSum){
                p1++;
            } else {
                res += (mid-p1+1);
                p2++;
            }
        }
        
        // merge sort
        p1 = lo; p2 = mid+1;
        vector<long> temp;
        while(p1<=mid and p2<=hi){
            if(v[p1] <= v[p2]){
                temp.push_back(v[p1++]);
            } else {
                temp.push_back(v[p2++]);
            }
        }
        while(p1<=mid){
            temp.push_back(v[p1++]);
        }
        while(p2<=hi){
            temp.push_back(v[p2++]);
        }
        for(int i=lo; i<=hi; i++){
            v[i] = temp[i-lo];
        }
        return res;
    }
    
    long countSumLessOrEqual(vector<long> & v, int lo, int hi, const int maxSum){
        if(lo >= hi) return 0;
        long mid = lo+(hi-lo)/2, res = 0;
        res += countSumLessOrEqual(v, lo, mid, maxSum);
        res += countSumLessOrEqual(v, mid+1, hi, maxSum);
        res += merge(v, lo, mid, hi, maxSum);
        return res;
    }
    
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        long n = nums.size(), c1, c2;
        vector<long> prefix(n+1);
        // prefix[i] = sum of first i elements i.e. nums[0, i)
        
        prefix[0] = 0;
        for(int i = 0; i<n; i++) prefix[i+1] = prefix[i]+nums[i];
        c1 = countSumLessOrEqual(prefix, 0, prefix.size()-1, lower-1);
        
        // rebuilding prefix as it is now sorted
        prefix[0] = 0;
        for(int i = 0; i<n; i++) prefix[i+1] = prefix[i]+nums[i];
        c2 = countSumLessOrEqual(prefix, 0, prefix.size()-1, upper);
        
        return c2-c1;
    }
};