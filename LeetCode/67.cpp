// https://leetcode.com/problems/add-binary/

// Method 1 (Hash map, O(n+m)):

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int n1 = nums1.size(), n2 = nums2.size();
        unordered_map<int, int> freq;
        for(auto &num:nums1){
            freq[num]++;
        }
        for(auto &num:nums2){
            if(freq.count(num)){
                ans.push_back(num);
                freq[num]--;
                if(freq[num] == 0){
                    freq.erase(num);
                }
            }
        }
        return ans;
    }
};

// Follow up 1:
// Method 2 (2 Pointer, O(nlogn+mlogm)):

class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int la = a.length(), lb = b.length();
        int pa = la-1, pb = lb-1;
        int sum = 0, carry = 0;
        while(pa>=0 and pb>=0){
            sum = a[pa]-'0'+b[pb]-'0'+carry;
            carry = sum/2;
            sum = sum%2;
            res.push_back(sum+'0');
            pa--;
            pb--;
        }
        while(pa>=0){
            sum = a[pa]-'0'+carry;
            carry = sum/2;
            sum = sum%2;
            res.push_back(sum+'0');
            pa--;
        }
        while(pb>=0){
            sum = b[pb]-'0'+carry;
            carry = sum/2;
            sum = sum%2;
            res.push_back(sum+'0');
            pb--;
        }
        if(carry){
            res.push_back(carry+'0');
        }
        return string(res.rbegin(), res.rend());
    }
};

// Follow up 2:
// Binary Search for each element in smaller array in the longer array. O(nlogm)

// Follow up 3:
// Option 1: Convert one array to freq hash map and calculate intersection with chunks of second array.
// Option 2: External sort (sort in chunks and merge all sorted chunks) both arrays, calculate intersction by chunking: