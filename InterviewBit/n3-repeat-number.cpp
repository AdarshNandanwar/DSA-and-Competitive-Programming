// https://www.interviewbit.com/problems/n3-repeat-number/

// Method 1 (Boyer-Moore Majority Vote algorithm, O(n) time, O(1) space)

int Solution::repeatedNumber(const vector<int> &nums) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int n = nums.size();
    if(n == 0) return -1;
    if(n == 1) return nums[0];
    
    // Boyer-Moore Majority Vote algorithm
    
    // See https://leetcode.com/problems/majority-element/ too
    
    // at max there can be only 2 majority n/3 elements
    
    int num1 = nums[0], num2 = nums[1], cnt1 = 0, cnt2 = 0;     // count = 0 is important
    for(int i = 0; i<n; i++){
        if(nums[i] == num1){ 
            cnt1++;
        } else if(nums[i] == num2){ 
            cnt2++;
        } else if(cnt1 == 0) {
            num1 = nums[i];
            cnt1++;
        } else if(cnt2 == 0) {
            num2 = nums[i];
            cnt2++;
        } else {
            cnt1--;
            cnt2--;
        }
    }
    
    // checking if num1 or num2 is the majority element
    cnt1 = 0; cnt2 = 0;
    for(auto i:nums){
        cnt1 += (i == num1);
        cnt2 += (i == num2);
    }
    if(cnt1 > n/3) return num1;
    if(cnt2 > n/3) return num2;
    
    return -1;        
}
