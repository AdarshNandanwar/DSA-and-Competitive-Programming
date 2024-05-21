// https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/



// Method 1 (Sorting, O(nlogn)):

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        vector<int> counts;
        int curCount = 1;
        for(int i=1; i<arr.size(); i++){
            if(arr[i] == arr[i-1]){
                curCount++;
            } else {
                counts.push_back(curCount);
                curCount = 1;
            }
        }
        counts.push_back(curCount);
        sort(counts.begin(), counts.end());
        int n = counts.size();
        for(int i=0; i<n; i++){
            if(counts[i] > k){
                return n-i;
            }
            k -= counts[i];
        }
        return 0;
    }
};

// Alternate Code (Slower):

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> freq;
        for(const int& ele:arr){
            freq[ele]++;
        }
        vector<int> counts;
        for(auto& i:freq){
            counts.push_back(i.second);
        }
        sort(counts.begin(), counts.end());
        for(int i=0; i<counts.size(); i++){
            if(counts[i] > k){
                return counts.size() - i;;
            }
            k -= counts[i];
        }
        return 0;
    }
};

// Alternate Code (More slower):

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> freq;
        for(const int& ele:arr){
            freq[ele]++;
        }
        sort(arr.begin(), arr.end(), [&freq](const int a, const int b){
            return freq[a] == freq[b] ? a < b : freq[a] < freq[b];
        });
        unordered_set<int> unique(arr.begin()+k ,arr.end());
        return unique.size();
    }
};

// Alternate Code (Even more slower):

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> freq;
        for(const int& ele:arr){
            freq[ele]++;
        }
        sort(arr.begin(), arr.end(), [&freq](const int a, const int b){
            return freq[a] == freq[b] ? a < b : freq[a] < freq[b];
        });
        for(const int& ele:arr){
            if(k == 0){
                break;
            }
            k--;
            freq[ele]--;
            if(freq[ele] == 0){
                freq.erase(ele);
            }
        }
        return freq.size();
    }
};
