// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int p1 = 0, p2 = n-1;
        while(p1<p2){
            if(numbers[p1] + numbers[p2] == target){
                return vector<int>({p1+1, p2+1});
            }if(numbers[p1] + numbers[p2] < target){
                p1++;
            }else {
                p2--;
            }
        }
        return vector<int>({p1+1, p2+1});
    }
};