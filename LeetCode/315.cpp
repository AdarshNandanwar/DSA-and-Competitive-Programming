// https://leetcode.com/problems/count-of-smaller-numbers-after-self/

// Method 1 (Merge Sort, O(nlogn)):

class Solution {
public:
    void mergeArrays(vector<pair<int, int>> & toSort, int low, int mid, int hi, vector<int> & counts){
        vector<pair<int, int>> sortedArray;
        int p1 = low, p2 = mid+1;
        while(p1<=mid and p2<=hi){
            if(toSort[p1].first <= toSort[p2].first){
                counts[toSort[p1].second] += (p2-(mid+1));
                sortedArray.push_back(toSort[p1]);
                p1++;
            } else {
                sortedArray.push_back(toSort[p2]);
                p2++;
            }
        }
        while(p1<=mid){
            counts[toSort[p1].second] += (p2-(mid+1));
            sortedArray.push_back(toSort[p1]);
            p1++;
        }
        while(p2<=hi){
            sortedArray.push_back(toSort[p2]);
            p2++;
        }
        for(int i=low; i<=hi; i++){
            toSort[i] = sortedArray[i-low];
        }
    }
    
    void mergeSort(vector<pair<int, int>> & toSort, int low, int hi, vector<int> & counts){
        if(low >= hi){
            return;
        }
        int mid = low+(hi-low)/2;
        mergeSort(toSort, low, mid, counts);
        mergeSort(toSort, mid+1, hi, counts);
        mergeArrays(toSort, low, mid, hi, counts);
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> counts(n, 0);
        // {value, index}
        vector<pair<int, int>> toSort;
        for(int i=0; i<n; i++){
            toSort.push_back({nums[i], i});
        }
        mergeSort(toSort, 0, n-1, counts);
        return counts;
    }
};

// Alternate Code:

class Solution {
    void mergeVectors(vector<int> & nums, int left, int mid, int right, vector<int> & smallerRight, vector<int> & originalIndex, vector<int> & buffer, vector<int> & newIndex){
        int n = nums.size();
        int p1 = left, p2 = mid+1;
        int bufferIndex = 0;
        while(p1<=mid and p2<=right){
            if(nums[p1] > nums[p2]){
                buffer[bufferIndex] = nums[p2];
                newIndex[bufferIndex] = originalIndex[p2];
                p2++;
            } else {
                smallerRight[originalIndex[p1]] += (p2-mid-1);
                buffer[bufferIndex] = nums[p1];
                newIndex[bufferIndex] = originalIndex[p1];
                p1++;                
            }
            bufferIndex++;
        }
        while(p1<=mid){
            smallerRight[originalIndex[p1]] += (right-mid);
            buffer[bufferIndex] = nums[p1];
            newIndex[bufferIndex] = originalIndex[p1];
            bufferIndex++;
            p1++; 
        }
        while(p2<=right){
            buffer[bufferIndex] = nums[p2];
            newIndex[bufferIndex] = originalIndex[p2];
            bufferIndex++;
            p2++;
        }
        for(int i=0; i<right-left+1; i++){
            nums[i+left] = buffer[i];
            originalIndex[i+left] = newIndex[i];
        }
    }
    
    void mergeSort(vector<int> & nums, int left, int right, vector<int> & smallerRight, vector<int> & originalIndex, vector<int> & buffer, vector<int> & newIndex){
        if(left>=right){
            return;
        }
        int mid = left+(right-left)/2;
        mergeSort(nums, left, mid, smallerRight, originalIndex, buffer, newIndex);
        mergeSort(nums, mid+1, right, smallerRight, originalIndex, buffer, newIndex);
        mergeVectors(nums, left, mid, right, smallerRight, originalIndex, buffer, newIndex);
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> smallerRight(n, 0);
        vector<int> originalIndex(n, 0);
        vector<int> buffer(n, 0);           // memory allocation done once here to prevent TLE
        vector<int> newIndex(n, 0);         // memory allocation done once here to prevent TLE
        for(int i=0; i<n; i++){
            originalIndex[i] = i;
        }
        mergeSort(nums, 0, n-1, smallerRight, originalIndex, buffer, newIndex);
        return smallerRight;
    }
};