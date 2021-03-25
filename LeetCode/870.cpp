// https://leetcode.com/problems/advantage-shuffle/

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<pair<int, int>> v;
        for(int i =0; i<n; i++){
            v.push_back({B[i], i});
        }
        sort(A.begin(), A.end());
        sort(v.begin(), v.end());
        
        vector<int> temp(A.size());
        int p1 = 0, p2 = n-1;
        for(int i=0; i<n; i++){
            if(A[i]>v[p1].first){
                temp[p1++] = A[i];
            } else {
                temp[p2--] = A[i];
            }
        }
        for(int i = 0; i<n; i++){
            A[v[i].second] = temp[i];
        }
        return A;
    }
};