// https://leetcode.com/problems/distant-barcodes/

// Method 1 (O(n)):

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n = barcodes.size(), maxFreq = 0, maxFreqNum;
        if(n <= 2) return vector<int>(barcodes.begin(), barcodes.end());
        vector<int> ans(n);
        
        unordered_map<int, int> freq;
        for(auto i:barcodes){
            freq[i]++;
            if(freq[i]>maxFreq){ 
                maxFreq = freq[i];
                maxFreqNum = i;
            }
        }
        
        int index, firstStart, secondStart;
        if(n%2){
            firstStart = 0;
            secondStart = 1;
        } else {
            firstStart = 1;
            secondStart = 0;
        }
        
        index = firstStart;
        for(int k = 0; k<maxFreq; k++, index+=2){
            if(index >= n) index = secondStart;
            ans[index] = maxFreqNum;
        }
        for(auto [i,j]:freq){
            if(i == maxFreqNum) continue;
            for(int k = 0; k<j; k++, index+=2){
                if(index >= n) index = secondStart;
                ans[index] = i;
            }
        }
        return ans;
    }
};

// Method 2 (O(nlogn)):

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n = barcodes.size();
        vector<int> ans;
        
        unordered_map<int, int> freq;
        for(auto i:barcodes) freq[i]++;
        
        sort(barcodes.begin(), barcodes.end(), [&](const int & a, const int & b){
            return freq[a]==freq[b]?a<b:freq[a]>freq[b];
        });   
        
        int p1 = 0, p2 = n/2;
        if(n%2){
            p2++;
            ans.push_back(barcodes[p1++]);
        }
        while(ans.size() < n){
            ans.push_back(barcodes[p2++]);
            if(ans.size() < n) ans.push_back(barcodes[p1++]);
        }
        return ans;
    }
};