// https://leetcode.com/problems/next-permutation/

// Method 1:

class Solution {
public:
    void nextPermutation(vector<int>& A) {
        int n = A.size(), i, j;
        for(i = n-2; i>=0; i--) if(A[i] < A[i+1]) break;
        if(i < 0){
            sort(A.begin(), A.end());
            return;
        }
        for(j = i; j+1<n; j++) if(A[j+1]<=A[i]) break;
        swap(A[i], A[j]);
        sort(A.begin()+i+1, A.end());
    }
};

// Method 2:

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i, ideal = -1;
        for(i = n-2; i>= 0; i--){
            if(nums[i] < nums[i+1]){
                ideal = i+1;
                for(int j = i+1; j<n; j++){
                    if(nums[i] >= nums[j]){
                        break;
                    } else {
                        ideal = j;
                    }
                }
                break;
            }
        }
        if(ideal == -1){
            reverse(nums.begin(), nums.end());
        } else {
            swap(nums[i], nums[ideal]);
            reverse(nums.begin()+i+1, nums.end());
        }
    }
};