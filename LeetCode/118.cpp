// https://leetcode.com/problems/pascals-triangle/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        vector<int> row;
        for(int i=0; i<numRows; i++){
            for(int j=i-1; j>=1; j--){
                row[j] += row[j-1];
            }
            row.push_back(1);
            triangle.push_back(row);
        }
        return triangle;
    }
};

// Alternate Code:

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 0) return {};
        if(numRows == 1) return {{1}};
        vector<vector<int>> pt(1, vector<int>(1, 1));
        for(int i = 1; i<numRows; i++){
            vector<int> row;
            for(int j = 0; j<i; j++){
                int ele = pt.back()[j];
                if(j!=0) ele += pt.back()[j-1];
                row.push_back(ele);
            }
            row.push_back(1);
            pt.push_back(row);
        }
        return pt;
    }
};