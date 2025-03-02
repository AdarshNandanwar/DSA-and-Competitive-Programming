// https://leetcode.com/problems/tuple-with-same-product/

// Method 1 (Set + Math, O(n2)):

class Solution {
    int nC2(int n){
        return (n * (n - 1)) / 2;
    }
public:
    int tupleSameProduct(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        vector<int> uniqueNums(s.begin(), s.end());
        int n = s.size();
        unordered_map<int, int> products;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                products[uniqueNums[i] * uniqueNums[j]]++;
            }
        }

        int res = 0;
        for(auto p:products){
            if(p.second > 1){
                res += (8 * nC2(p.second));
            }
        }

        return res;
    }
};
