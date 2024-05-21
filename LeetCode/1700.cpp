// https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/

// Method 1 (Counting, O(n) time, O(1) space):

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int circular = 0, square = 0;
        int n = students.size();
        for(int i=0; i<n; i++){
            if(students[i] == 0){
                circular++;
            } else {
                square++;
            }
        }
        for(int i=0; i<n; i++){
            if(sandwiches[i] == 0){
                if(circular > 0){
                    circular--;
                } else {
                    return n-i;
                }
            } else {
                if(square > 0){
                    square--;
                } else {
                    return n-i;
                }
            }            
        }
        return 0;
    }
};
