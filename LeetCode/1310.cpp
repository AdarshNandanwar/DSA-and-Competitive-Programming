// https://leetcode.com/problems/xor-queries-of-a-subarray/

// Method 1 (Suffix XOR, O(n+m)):

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> suffixXor(n+1);
        for(int i=n-1; i>=0; i--){
            suffixXor[i] = arr[i] ^ suffixXor[i+1];
        }

        int m = queries.size();
        vector<int> answer(m);
        for(int i=0; i<m; i++){
            answer[i] = suffixXor[queries[i][0]] ^ suffixXor[queries[i][1]+1];
        }

        return answer;
    }
};
