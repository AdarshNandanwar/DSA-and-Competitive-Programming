// https://leetcode.com/problems/relative-sort-array/

unordered_map<int, int> m;

bool isPresent(int a){
    if(m.find(a) == m.end()) return false;
    return true;
}

bool comp(int a, int b){
    if(isPresent(a) && isPresent(b)){
        return m[a] < m[b];
    } else if(isPresent(a)){
        return true;
    } else if(isPresent(b)){
        return false;
    } else {
        return a<b;
    }
}

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        m.clear();
        for(int i = 0; i<arr2.size(); i++){
            m[arr2[i]] = i;
        }
        sort(arr1.begin(), arr1.end(), comp);
        return arr1;
    }
};