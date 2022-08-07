// https://leetcode.com/problems/queue-reconstruction-by-height/

// Method 1 (Fenwick Tree, o(nlogn)):

class Solution {
    class FenwickTree{
        vector<int> BIT;
    public:
        void update(int index, int value){
            int n = BIT.size();
            for(int i=index; i<n; i+=(i&-i)){
                BIT[i] += value;
            }
        }
        int prefixSum(int index){
            int prefixSum = 0;
            for(int i=index; i>0; i-=(i&-i)){
                prefixSum += BIT[i];
            }
            return prefixSum;
        }
        FenwickTree(int n){
            BIT = vector<int>(n+1, 0);
        }
    };
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        sort(people.begin(), people.end(), [](const vector<int> & a, const vector<int> & b){
            return a[0]==b[0] ? a[1]>b[1] : a[0]<b[0];
        });
        // Fenwick Tree's array stores boolean values telling if the pos is empty.
        // Prefix Sum will tell number of empty positions on or before index.
        // Use binary search to find the ith empty position.
        FenwickTree * BIT = new FenwickTree(n);
        for(int i=0; i<n; i++){
            BIT->update(i+1, 1);
        }
        vector<vector<int>> reconstrutedQueue(n, {-1, -1});
        for(auto &person:people){
            int height = person[0];
            int frontTaller = person[1];
            int emptyPos = frontTaller+1;
            // Find the index of emptyPos'th empty position.
            // FT First T
            int hi = n-1, lo = 0, mid;
            while(lo<hi){
                mid = lo+(hi-lo)/2;
                if(BIT->prefixSum(mid+1)>=emptyPos){
                    hi = mid;
                } else {
                    lo = mid+1;
                }
            }
            reconstrutedQueue[lo] = person;
            BIT->update(lo+1, -1);
        }
        return reconstrutedQueue;
    }
};

// Method 2 (Sorting, O(n2)):

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        sort(people.begin(), people.end());
        vector<vector<int>> reconstrutedQueue(n, {-1, -1});
        for(auto &person:people){
            int height = person[0];
            int frontTaller = person[1];
            int index = 0;
            // Leave positions for people taller or equal height than current person
            while(frontTaller){
                if(reconstrutedQueue[index][0] == -1 or reconstrutedQueue[index][0] == height){
                    frontTaller--;
                }
                index++;
            }
            // Find next empty position
            while(reconstrutedQueue[index][0] != -1){
                index++;
            }
            reconstrutedQueue[index] = person;
        }
        return reconstrutedQueue;
    }
};

// Alternate Code:

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        sort(people.begin(), people.end(), [](const vector<int> & a, const vector<int> & b){
            return a[0]==b[0] ? a[1]>b[1] : a[0]<b[0];
        });
        vector<vector<int>> reconstrutedQueue(n, {-1, -1});
        for(auto &person:people){
            int height = person[0];
            int frontTaller = person[1];
            int index = 0;
            // Leave positions for people taller or equal height than current person
            while(frontTaller){
                if(reconstrutedQueue[index][0] == -1){
                    frontTaller--;
                }
                index++;
            }
            // Find next empty position
            while(reconstrutedQueue[index][0] != -1){
                index++;
            }
            reconstrutedQueue[index] = person;
        }
        return reconstrutedQueue;
    }
};

// Method 3 (Sorting, O(n2)):

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int> & a, const vector<int> & b){
            return a[0]==b[0] ? a[1]<b[1] : a[0]>b[0];
        });
        // Queue alwas contains people taller than cur
        // So, inserting the current person will never interfere with
        // the frontTaller count if the people already in the queue.
        vector<vector<int>> reconstrutedQueue;
        for(auto &person:people){
            int height = person[0];
            int frontTaller = person[1];
            auto pos = reconstrutedQueue.begin();
            while(frontTaller){
                if((*pos)[0] >= height){
                    frontTaller--;
                }
                pos++;
            }
            reconstrutedQueue.insert(pos, person);
        }
        return reconstrutedQueue;
    }
};