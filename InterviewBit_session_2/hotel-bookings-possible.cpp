// https://www.interviewbit.com/problems/hotel-bookings-possible/

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    vector<vector<int>> v;
    int n = arrive.size();
    for(int i = 0; i<n; i++){
        v.push_back({arrive[i], 1});
        v.push_back({depart[i], -1});
    }
    sort(v.begin(), v.end());
    int cur = 0;
    for(auto &i:v){
        cur += i[1];
        if(cur>K) return 0;
    }
    return 1;
}
