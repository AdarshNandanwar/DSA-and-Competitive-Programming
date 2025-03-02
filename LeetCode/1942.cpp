// https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/

// Method 1 (Min Heaps, O(nlogn)):

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {

        int targetArrivalTime = times[targetFriend][0]; // arival times are unique

        sort(times.begin(), times.end());

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> occupied; // {endtime, seat number}
        priority_queue<int, vector<int>, greater<int>> vacantSeats;
        
        int n = times.size();
        for(vector<int> & time : times){
            int arrivalTime = time[0];
            int leavingTime = time[1];
            while(!occupied.empty() and occupied.top()[0] <= arrivalTime){
                int seatNumber = occupied.top()[1];
                occupied.pop();
                vacantSeats.push(seatNumber);
            }

            int allottedSeatNumber = -1;
            if(!vacantSeats.empty()){
                allottedSeatNumber = vacantSeats.top();
                vacantSeats.pop();
            } else {
                allottedSeatNumber = occupied.size();
            }
            occupied.push({leavingTime, allottedSeatNumber});
            
            if(arrivalTime == targetArrivalTime){
                return allottedSeatNumber;
            }
        }

        return -1;
    }
};
