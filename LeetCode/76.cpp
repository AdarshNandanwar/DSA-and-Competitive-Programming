// https://leetcode.com/problems/minimum-window-substring/

// Method 1 (2 Pointer Window, O(n)):

class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length(), n = t.length();
        int remainingCount = n;
        unordered_map<char, int> remainingFreq;
        int minWindowLength = INT_MAX;
        int minWindowStartIndex = -1;

        for(const char c:t){
            remainingFreq[c]++;
        }

        int i = 0, j = 0;
        // [i,j) should be the min window that contains all letters in t
        while(true){
            // Expand window till all characters in t are found
            while(j<m and remainingCount){
                if(remainingFreq[s[j]] > 0){
                    remainingCount--;
                }
                remainingFreq[s[j]]--;
                j++;
            }
            if(remainingCount){
                break;
            }

            // [i,j) now contains all letters in t
            while(i<j){
                if(remainingFreq[s[i]] == 0){
                    break;
                }
                remainingFreq[s[i]]++;
                i++;
            }
            // [i,j) is min window that contains all letters in t that ends at j

            if(minWindowLength > j-i){
                minWindowLength = j-i;
                minWindowStartIndex = i;
            }
            
            // increase i to make the window incomplete
            remainingFreq[s[i]]++;
            if(remainingFreq[s[i]] > 0){
                remainingCount++;
            }
            i++;
        }
        return minWindowStartIndex == -1 ? "" : s.substr(minWindowStartIndex, minWindowLength);
    }
};

// Alternate Code:

class Solution {
public:
    string minWindow(string s, string t) {
        string ans = "";
        int ansLen = INT_MAX;
        int remaining = 0;
        unordered_map<char, int> freq;
        for(auto & c:t){
            freq[c]--;
            remaining++;
        }
        int n = s.length(), p1 = 0, p2 = 0;
        while(p2<n){
            while(remaining and p2<n){
                if(freq[s[p2]] < 0){
                    remaining--;
                }
                freq[s[p2]]++;
                p2++;
            }
            if(remaining){
                break;
            }
            while(remaining==0 and p1<=p2){
                freq[s[p1]]--;
                if(freq[s[p1]] < 0){
                    remaining++;
                }
                p1++;
            }
            if(ansLen > p2-(p1-1)){
                ansLen = p2-(p1-1);
                ans = s.substr(p1-1, ansLen);
            }
        }
        return ans;
    }
};