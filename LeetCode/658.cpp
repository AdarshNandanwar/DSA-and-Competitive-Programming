// https://leetcode.com/problems/find-k-closest-elements/

// Method 1 (Binary Search, 2 Pointer, O(k+logn)):

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto left = lower_bound(arr.begin(), arr.end(), x);
        if(left == arr.end()){
            return vector<int>(arr.end()-k, arr.end());
        }
        vector<int> prefix, suffix;
        auto right = left;
        left = prev(left);
        while(prefix.size()+suffix.size() < k){
            if(left >= arr.begin()){
                if(right < arr.end()){
                    if(x-*left <= *right-x){
                        prefix.push_back(*left);
                        left = prev(left);
                    } else {                        
                        suffix.push_back(*right);
                        right = next(right);
                    }
                } else {
                    prefix.push_back(*left);
                    left = prev(left);
                }
            } else {
                if(right < arr.end()){
                    suffix.push_back(*right);
                    right = next(right);
                } else {
                    // error
                }
            }
        }
        reverse(prefix.begin(), prefix.end());
        for(auto &i:suffix){
            prefix.push_back(i);
        }
        return prefix;
    }
};