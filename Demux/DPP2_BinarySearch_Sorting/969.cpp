// https://leetcode.com/problems/pancake-sorting/

// Method 1:

class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        int n = A.size();
        vector<int> k;
        for(int i = n; i>1; i--){
            int mi = max_element(A.begin(), A.begin()+i)-A.begin();
            k.push_back(mi+1);
            reverse(A.begin(), A.begin()+mi+1);
            k.push_back(i);
            reverse(A.begin(), A.begin()+i);
        }
        return k;
    }
};

// Method 2 (Slower):

class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        int n = A.size();
        vector<int> k;
        for(int i = 1; i<n; i++){
            if(A[i] >= A[i-1]) continue;
            int lb = lower_bound(A.begin(), A.begin()+i, A[i])-A.begin();
            reverse(A.begin(), A.begin()+i);
            k.push_back(i);
            reverse(A.begin(), A.begin()+i-lb);
            k.push_back(i-lb);
            reverse(A.begin(), A.begin()+i);
            k.push_back(i);
            reverse(A.begin(), A.begin()+i+1);
            k.push_back(i+1);
            reverse(A.begin(), A.begin()+i-lb+1);
            k.push_back(i-lb+1);
            reverse(A.begin(), A.begin()+i+1);
            k.push_back(i+1);
        }
        return k;
    }
};