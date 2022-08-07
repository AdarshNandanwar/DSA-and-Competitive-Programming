// https://leetcode.com/problems/reorganize-string/

// Method 1 (Greedy, O(n)):

class Solution {
public:
    string reorganizeString(string S) {
        unordered_map<char, int> freq;
        int maxF = 0, n = S.length();
        char maxEle;
        if(n == 0) return "";
        for(auto c:S) {
            freq[c]++;
            if(maxF < freq[c]){
                maxF = freq[c];
                maxEle = c;
            }
        }
        
        if(maxF > (n+1)/2) return "";
        
        string res(n, ' ');
        int ind = 0;
        
        // seperating handling the case of maxEle
        for(int j = 0; j<maxF; j++){
            if(ind >= n) ind = 1;
            res[ind] = maxEle;
            ind += 2;
        }
        
        for(auto i:freq){
            if(i.first == maxEle) continue;
            for(int j = 0; j<i.second; j++){
                if(ind >= n) ind = 1;
                res[ind] = i.first;
                ind += 2;
            }
        }
        return res;
    }
};

// Method 2 (Sorting, Virtual Indexing, O(nlogn)):

class Solution {
public:
    int getIndex(int i, int n){
        // 0 1 2 3 => 0 2 1 3
        if(n%2 == 0){
            if(2*i < n){
                return 2*i;
            } else {
                return 1+(2*i)%n;
            }
        } else {
            return (2*i)%n;
        }    
    }
    
    string reorganizeString(string s) {
        unordered_map<char, int> freq;
        for(auto &c:s){
            freq[c]++;
        }
        sort(s.begin(), s.end(), [&freq](const char & a, const char & b){
            return freq[a] == freq[b] ? a<b : freq[a] > freq[b];
        });
        
        int n =s.length();
        string newS = string(s);
        for(int i=0; i<n; i++){
            newS[getIndex(i, n)] = s[i];
        }
        for(int i=1; i<n; i++){
            if(newS[i] == newS[i-1]) return "";
        }
        return newS;
    }
};