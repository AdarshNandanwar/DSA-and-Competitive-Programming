// https://www.interviewbit.com/problems/hotel-bookings-possible/

// Method 1 (Sorting, Priority Queue, O(nlogn)):

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    int n = arrive.size();
    vector<vector<int>> interval;
    for(int i = 0; i<n; i++) if(arrive[i] < depart[i]) interval.push_back({arrive[i], depart[i]});
    sort(interval.begin(), interval.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i<interval.size(); i++){
        while(!pq.empty() and interval[i][0]>=pq.top()) pq.pop();
        if(pq.size() == K) return 0;
        pq.push(interval[i][1]);
    }
    return 1;
}
