// https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/

// Method 1 (Hash Map, O(n) time, O(n) space):

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> freq;
        for(int i=0; i<n; i++){
            freq[target[i]]++;
        }
        for(int i=0; i<n; i++){
            freq[arr[i]]--;
            if(freq[arr[i]] < 0){
                return false;
            }
        }
        return true;
    }
};

// Method 2 (Sort, O(nlogn) time, O(1) space):

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int n = arr.size();
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());
        for(int i=0; i<n; i++){
            if(target[i] != arr[i]){
                return false;
            }
        }
        return true;
    }
};
