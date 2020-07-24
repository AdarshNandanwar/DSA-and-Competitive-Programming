// https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/

class Solution {
public:
    int computeSum(vector<int> & arr, int x){
        int i = 0, n = arr.size(), sum = 0;
        for(i=0; i<n; i++){
            if(arr[i]<=x){
                sum += arr[i];
            } else {
                sum += x;
            }
        }
        return sum;
    }
    
    int findMin(vector<int> & arr, int target, int upper){
        int n = arr.size(), lo, hi, mid;
        
        // FFFTT
        // p(i): computeSum(arr, i) > target
        // Last F
        
        lo = 0, hi = upper;
        while(lo<hi){
            mid = lo+(hi-lo+1)/2;
            if(computeSum(arr, mid) > target)
                hi = mid-1;
            else
                lo = mid;
        }
        return lo;
    }
    
    int findBestValue(vector<int>& arr, int target) {
        // Finding max element
        int max_ele = INT_MIN, i, n = arr.size();
        int r1, r2, t1, t2;
        
        for(i=0; i<n; i++){
            max_ele = max(max_ele, arr[i]);
        }
        
        r1 = findMin(arr, target, max_ele);
        
        t1 = abs(target-computeSum(arr, r1));
        t2 = abs(target-computeSum(arr, r1+1));
        
        return t1<=t2? r1: r1+1;
    }
};