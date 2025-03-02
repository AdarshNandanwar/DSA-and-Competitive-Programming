// https://leetcode.com/problems/number-of-flowers-in-full-bloom/

// Method 1 (Binary Search, O((m+n)logn)):

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n = flowers.size(), m = people.size();

        vector<int> startTimes(n), endTimes(n);
        for(int i=0; i<n; i++){
            startTimes[i] = flowers[i][0];
            endTimes[i] = flowers[i][1];
        }

        sort(startTimes.begin(), startTimes.end());
        sort(endTimes.begin(), endTimes.end());
        
        vector<int> answer(m);
        for(int i=0; i<m; i++){
            int countStart = upper_bound(startTimes.begin(), startTimes.end(), people[i]) - startTimes.begin();
            int countEnd = lower_bound(endTimes.begin(), endTimes.end(), people[i]) - endTimes.begin();
            answer[i] = countStart - countEnd;
        }

        return answer;
    }
};

// Method 2 (Min Heap, O(nlogn + mlogm + mlogn)):

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n = flowers.size(), m = people.size();
        vector<int> original = people;

        sort(flowers.begin(), flowers.end());
        sort(people.begin(), people.end());

        unordered_map<int, int> bloomCount;
        priority_queue<int, vector<int>, greater<int>> pq;
        int flowerIndex = 0;
        for(int i=0; i<m; i++){
            while(flowerIndex < n and flowers[flowerIndex][0] <= people[i]){
                pq.push(flowers[flowerIndex][1]);
                flowerIndex++;
            }
            while(!pq.empty() and pq.top() < people[i]){
                pq.pop();
            }
            bloomCount[people[i]] = pq.size();
        }

        vector<int> answer(m);
        for(int i=0; i<m; i++){
            answer[i] = bloomCount[original[i]];
        }

        return answer;
    }
};

// Method 3 (Brute Force, O(n*m), TLE):

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n = flowers.size(), m = people.size();
        vector<int> answer(m);
        for(int i=0; i<m; i++){
            int count = 0;
            for(int j=0; j<n; j++){
                if(flowers[j][0] <= people[i] and people[i] <= flowers[j][1]){
                    count++;
                }
            }
            answer[i] = count;
        }
        return answer;
    }
};
