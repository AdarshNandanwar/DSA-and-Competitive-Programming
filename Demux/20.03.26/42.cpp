// https://leetcode.com/problems/trapping-rain-water/

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

// Method 1 (Stack, Clean Code, O(n)):

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), base, water = 0, h;
        
        // Next Greater Logic
        
        stack<int> st;
        for(int i = 0; i<n; i++){
            while(!st.empty() and height[st.top()] < height[i]){
                // base is the height of the lower edge of the water rectange
                base = height[st.top()];
                st.pop();
                if(!st.empty()){
                    h = min(height[st.top()], height[i])-base;
                    water += ((i-st.top()-1)*h);
                }
            }
            st.push(i);
        }
        return water;
    }
};

// Method 1 (Unclean Code, O(n)):

int trap(vector<int>& height) {
    int p1 = 0, p2 = 1;
    long long water = 0;
    
    while(p2 < height.size()){
        if(p1<p2 && height[p1] <= height[p2]){
            water += (p2-p1-1)*height[p1];
            p1++;
            while(p1<p2){
                water -= height[p1];
                p1++;
            }
        }
        p2++;
    }
    reverse(height.begin(), height.end());
    p1 = 0;
    p2 = 1;
    while(p2 < height.size()){
        if(height[p1] <= height[p2]){
            water += (p2-p1-1)*height[p1];
            p1++;
            while(p1<p2){
                water -= height[p1];
                p1++;
            }
        }
        p2++;
    }
    int max_height = 0;
    for(int i = 0; i < height.size(); i++){
        max_height = max(max_height, height[i]);
    }
    vector<int> h;
    for(int i = 0; i<height.size(); i++){
        if(height[i] == max_height){
            h.push_back(i);
        }
    }
    for(int i = 1; i<h.size(); i++){
        for(int j = h[i-1]+1; j<h[i]; j++){
            water -= (max_height-height[j]);
        }
    }
    return water;
}
 
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<trap(v)<<endl;


    return 0;
}