// https://leetcode.com/problems/relative-sort-array/

// Method 1 (Counting Sort, O(n+m+k)):

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(), m = arr2.size();

        vector<int> priority(1001, -1);
        for(int i=0; i<arr2.size(); i++){
            priority[arr2[i]] = i;
        }

        vector<int> priorityCounts(m, 0);
        for(int num:arr1){
            if(priority[num] != -1){
                priorityCounts[priority[num]]++;
            }
        }
        vector<int> counts(1001, 0);
        for(int num:arr1){
            counts[num]++;
        }

        int index = 0;
        for(int priority=0; priority<m; priority++){
            while(priorityCounts[priority] > 0){
                arr1[index++] = arr2[priority];
                priorityCounts[priority]--;
            }
        }
        for(int num=0; num<counts.size(); num++){
            if(priority[num] != -1){
                continue;
            }
            while(counts[num] > 0){
                arr1[index++] = num;
                counts[num]--;
            }
        }

        return arr1;
    }
};

// Method 2 (Vector, Lambda Function Sorting, O(nlogn)):

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> priority(1001, -1);
        for(int i=0; i<arr2.size(); i++){
            priority[arr2[i]] = i;
        }
        sort(arr1.begin(), arr1.end(), [&priority](const int a, const int b){
            if(priority[a] != -1){
                if(priority[b] != -1){
                    return priority[a] < priority[b];
                } else {
                    return true;
                }
            } else {
                if(priority[b] != -1){
                    return false;
                } else {
                    return a < b;
                }
            }
        });
        return arr1;
    }
};

// Method 3 (Hash Map, Lambda Function Sorting, O(nlogn)):

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> priority;
        for(int i=0; i<arr2.size(); i++){
            priority[arr2[i]] = i;
        }
        sort(arr1.begin(), arr1.end(), [&priority](const int a, const int b){
            if(priority.count(a)){
                if(priority.count(b)){
                    return priority[a] < priority[b];
                } else {
                    return true;
                }
            } else {
                if(priority.count(b)){
                    return false;
                } else {
                    return a < b;
                }
            }
        });
        return arr1;
    }
};
