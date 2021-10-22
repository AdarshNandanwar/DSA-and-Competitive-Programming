// https://leetcode.com/problems/next-greater-element-i/

// Method 1 (Stack, O(n1+n2)):

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        unordered_map<int, int> next;
        stack<int> st;
        for(int j = 0; j<n2; j++){
            while(!st.empty() and nums2[st.top()] < nums2[j]){
                next[nums2[st.top()]] = nums2[j];
                st.pop();
            }
            st.push(j);
        }
        while(!st.empty()){
            next[nums2[st.top()]] = -1;
            st.pop();
        }
        vector<int> ans;
        for(int i = 0; i<n1; i++){
            ans.push_back(next[nums1[i]]);
        }
        return ans;
    }
};

// Method 2 (O(n2)):

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size(), next;
        vector<int> ans;
        for(int i = 0; i<n1; i++){
            bool found = 0;
            next = -1;
            for(int j = 0; j<n2; j++){
                if(nums1[i] == nums2[j]) found = 1;
                if(found and nums2[j] > nums1[i]){
                    next = nums2[j];
                    break;
                }
            }
            ans.push_back(next);
        }
        return ans;
    }
};