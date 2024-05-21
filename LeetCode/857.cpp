// https://leetcode.com/problems/minimum-cost-to-hire-k-workers/

// Method 1 (Sorting and Max Heap, O(n*log(n))):

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, int>> wageByQuality(n);
        for(int i=0; i<n; i++){
            wageByQuality[i] = make_pair((double)wage[i]/quality[i], i);
        }
        
        // Cost = Sum of qualities of all selected workers * max ratio of wage by quality
        
        // We take the group with minimum max ratio (by sorting),
        // and then remove the worker with highest quality (in order to reduce the sum)
        // and add next worker with the lowest ratio.

        sort(wageByQuality.begin(), wageByQuality.end());

        int qualitySum = 0;
        priority_queue<int, vector<int>> pq;
        for(int i=0; i<k; i++){
            int curQuality = quality[wageByQuality[i].second];
            pq.push(curQuality);
            qualitySum += curQuality;
        }

        double minCost = qualitySum*wageByQuality[k-1].first;
        for(int i=k; i<n; i++){
            int poppedQuantity = pq.top();
            pq.pop();
            qualitySum -= poppedQuantity;

            int curQuality = quality[wageByQuality[i].second];
            pq.push(curQuality);
            qualitySum += curQuality;

            minCost = min(minCost, qualitySum*wageByQuality[i].first);
        }

        return minCost;
    }
};
