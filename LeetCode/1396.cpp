// https://leetcode.com/problems/design-underground-system/

// Method 1 (Hash Tables, O(1)):

class UndergroundSystem {
    // {id => {sourceStation, checkInTime}}
    unordered_map<int, pair<string, int>> idToSource;
    // {string => {durationSum, ticketCount}}
    unordered_map<string, pair<long, int>> travelTimes;
public:
    UndergroundSystem() {
        idToSource.clear();
        travelTimes.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        idToSource[id] = make_pair(stationName, t);
    }
    
    void checkOut(int id, string stationName, int t) {
        string sourceStation = idToSource[id].first;
        int checkInTime = idToSource[id].second;
        string ticketHash = sourceStation+"#"+stationName;
        long durationSum = t-checkInTime;
        int ticketCount = 1;
        if(travelTimes.count(ticketHash)){
            durationSum += travelTimes[ticketHash].first;
            ticketCount += travelTimes[ticketHash].second;
        }
        travelTimes[ticketHash] = make_pair(durationSum, ticketCount);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string ticketHash = startStation+"#"+endStation;
        return (double)travelTimes[ticketHash].first/travelTimes[ticketHash].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */