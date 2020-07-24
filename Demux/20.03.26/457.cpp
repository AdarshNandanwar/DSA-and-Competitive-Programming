// https://leetcode.com/problems/circular-array-loop/

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

// Method 1 (Slow Fast Pointer, Clean Code, O(n)):

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        // slow fast pointer method
        int slow, fast, n = nums.size(), dir;
        for(int i = 0; i<n; i++){
            if(abs(nums[i]) == n) continue;
            slow = fast = i;
            dir = i>0;
            while(1){
                if(nums[slow]>0 != dir or nums[fast]>0 != dir or abs(nums[slow]) == n or abs(nums[fast]) == n) break;
                slow = (slow+nums[slow])%n;
                if(slow<0) slow+=n;
                fast = (fast+nums[fast])%n;
                if(fast<0) fast+=n;
                if(nums[fast]>0 != dir or abs(nums[fast]) == n) break;
                fast = (fast+nums[fast])%n;
                if(fast<0) fast+=n;
                if(slow == fast) return true;
            }
        }
        return false;
    }
};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v = {1,-2};
    cout<<circularArrayLoop(v)<<endl;
    return 0;
}