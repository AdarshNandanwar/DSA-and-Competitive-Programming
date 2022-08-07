// https://leetcode.com/problems/largest-number/

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