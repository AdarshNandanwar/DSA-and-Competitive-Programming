// https://leetcode.com/problems/largest-number/

// Method 1 (Sorting, O(n*m + nlogn)):

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // 76543
        // 765
        // 67
        
        int n = nums.size();
        vector<string> numStrings(n);
        for(int i=0; i<n; i++){
            numStrings[i] = to_string(nums[i]);
        }

        sort(numStrings.begin(), numStrings.end(), [](const string & a, const string & b){
            return a+b > b+a;
        });

        string number;
        for(const string & s:numStrings){
            number += s;
        }

        int len = number.size();
        int startIndex = 0;
        while(startIndex < len and number[startIndex] == '0'){
            startIndex++;
        }

        if(startIndex == 0){
            return number;
        } else if(startIndex == len){
            return "0";
        } else {
            return number.substr(startIndex);
        }
    }
};

// Alternate Code:

bool comparator(string s1, string s2){
    return s1+s2>s2+s1;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size(), zero_count = 0;
        vector<string> str(n);
        for(int i = 0; i<n; i++){
            str[i] = to_string(nums[i]);
        }
        sort(str.begin(), str.end(), comparator);
        string ans = "";
        for(auto itr:str){
            ans += itr;
        }
        while(ans.length() and ans[0] == '0'){
            ans = ans.substr(1);
        }
        if(!ans.length()){
            ans = "0";
        }
        return ans;
    }
};