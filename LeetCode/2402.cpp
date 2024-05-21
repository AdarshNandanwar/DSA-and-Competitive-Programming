// https://leetcode.com/problems/meeting-rooms-iii/

// Method 1 (Priority Queue, O(nlogn)):

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<long> meetingCounts(n, 0);
        priority_queue<long, vector<long>, greater<long>> freeRooms;
        // {When will the room be free?, Room index}
        priority_queue<vector<long>, vector<vector<long>>, greater<vector<long>>> occupiedRooms;
        for(long i=0; i<n; i++){
            freeRooms.push(i);
        }
        for(const auto& meeting:meetings){
            long meetingStartTime = meeting[0];

            while(!occupiedRooms.empty() and occupiedRooms.top()[0] <= meetingStartTime){
                freeRooms.push(occupiedRooms.top()[1]);
                occupiedRooms.pop();
            }

            long roomIndex = -1;
            if(freeRooms.empty()){
                roomIndex = occupiedRooms.top()[1];
                meetingStartTime = occupiedRooms.top()[0];
                occupiedRooms.pop();
            } else {
                roomIndex = freeRooms.top();
                freeRooms.pop();
            }
            meetingCounts[roomIndex]++;

            long meetingDuration = meeting[1] - meeting[0];
            occupiedRooms.push({meetingStartTime + meetingDuration, roomIndex});
        }
        return max_element(meetingCounts.begin(), meetingCounts.end()) - meetingCounts.begin();
    }
};
