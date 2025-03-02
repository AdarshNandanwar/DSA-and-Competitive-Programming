class Solution {


    void stlSort(vector<int>& nums){
        sort(nums.begin(), nums.end());
    }


    void bubbleSort(vector<int>& nums){
        int n = nums.size();

        for(int i=0; i<n; i++){
            for(int j=0; j<n-1-i; j++){
                if(nums[j] > nums[j+1]){
                    swap(nums[j], nums[j+1]);
                }
            }
        }
    }


    void selectionSort(vector<int>& nums){
        int n = nums.size();

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(nums[i] > nums[j]){
                    swap(nums[i], nums[j]);
                }
            }
        }
    }


    void insertionSort(vector<int>& nums){
        int n = nums.size();

        for(int i=1; i<n; i++){
            // Assume [0, i-1] is sorted
            int val = nums[i];
            int j = i-1;
            while(j>=0 and nums[j]>val){
                nums[j+1] = nums[j];
                j--;
            }
            nums[j+1] = val;
        }
    }


    void countSort(vector<int>& nums){

        // For smaller set of values, a vector can be used for O(n) time
        map<int, int> freq;

        for(int num:nums){
            freq[num]++;
        }

        int index = 0;
        for(auto entry:freq){
            for(int i=0; i<entry.second; i++){
                nums[index++] = entry.first;
            }
        }
    }


    void heapSort(vector<int>& nums){
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int num:nums){
            pq.push(num);
        }

        for(int i=0; i<nums.size(); i++){
            nums[i] = pq.top();
            pq.pop();
        }
    }


    void quickSort(vector<int>& nums, int st, int end){
        // [st, end)
        if(end - st <= 1){
            return;
        }

        int pivot = nums[end-1];
        int p1 = st, p2 = end-1;
        // [p1, p2)
        while(p1 < p2){
            if(nums[p1] < pivot){
                p1++;
            } else {
                swap(nums[p1], nums[p2-1]);
                p2--;
            }
        }
        // [st, p2) < pivot
        // [p2, end-1) >= pivot
        // [end-1] == pivot

        swap(nums[p2], nums[end-1]);
        
        quickSort(nums, st, p2);
        quickSort(nums, p2+1, end);
    }


    void merge(vector<int>& nums, int st, int mid, int end){
        int n = end-st;
        vector<int> temp(n);
        int p1 = st, p2 = mid, index = 0;
        while(p1<mid and p2<end){
            if(nums[p1] < nums[p2]){
                temp[index++] = nums[p1++];
            } else {
                temp[index++] = nums[p2++];
            }
        }
        while(p1<mid){
            temp[index++] = nums[p1++];
        }
        while(p2<end){
            temp[index++] = nums[p2++];
        }
        for(int i=0; i<n; i++){
            nums[st+i] = temp[i];
        }
    }
    void mergeSort(vector<int>& nums, int st, int end){
        // [st, end)]
        if(end - st <= 1){
            return;
        }

        int mid = st + (end-st)/2;
        mergeSort(nums, st, mid);
        mergeSort(nums, mid, end);

        merge(nums, st, mid, end);
    }


public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();

        // // STL Sort (O(n2)):
        // stlSort(nums);

        // // Bubble Sort (O(n2)):
        // bubbleSort(nums);

        // // Selection Sort (O(n2)):
        // selectionSort(nums);

        // // Insertion Sort (O(n2)):
        // insertionSort(nums);

        // // Count Sort (O(n) with vectors, O(nlogn) with map):
        // countSort(nums);

        // // Heap Sort (O(nlogn)):
        // heapSort(nums);

        // // Quick Sort (average O(nlogn), worst O(n2)):
        // quickSort(nums, 0, n);

        // Merge Sort (O(nlogn)):
        mergeSort(nums, 0, n);

        return nums;
    }
};