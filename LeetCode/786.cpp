// https://leetcode.com/problems/k-th-smallest-prime-fraction/

// Method 1 (Priority Queue, O((n+k)logn) = O(nlogn)):

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();

        // {fraction, {numeratorIndex, denominatorIndex}}
        priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<pair<double, pair<int, int>>>> pq;
        for(int i=0; i<n-1; i++){
            double fraction = (double)arr[i]/arr[n-1];
            pq.push(make_pair(fraction, make_pair(i, n-1)));
        }

        for(int i=0; i<k-1; i++){
            auto cur = pq.top();
            pq.pop();
            int numeratorIndex = cur.second.first;
            int curDenominatorIndex = cur.second.second;
            int nextDenominatorIndex = curDenominatorIndex-1;
            if(numeratorIndex < nextDenominatorIndex){
                double fraction = (double)arr[numeratorIndex]/arr[nextDenominatorIndex];
                pq.push(make_pair(fraction, make_pair(numeratorIndex, nextDenominatorIndex)));
            }
        }
        
        return {arr[pq.top().second.first], arr[pq.top().second.second]};
    }
};

// Method 2 (Brute Force, O(n*n*log(n))):

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        vector<pair<double, pair<int, int>>> fraction;
        for(double i=0; i<n; i++){
            for(double j = i+1; j<n; j++){
                fraction.push_back(make_pair(((double)arr[i])/arr[j], make_pair(i, j)));
            }
        }
        sort(fraction.begin(), fraction.end());
        return {arr[fraction[k-1].second.first], arr[fraction[k-1].second.second]};
    }
};
