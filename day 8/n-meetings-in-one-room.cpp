// level - medium
// https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

// tc : O(n * log(n))
// sc : O(n)

class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        
        int n = (int)start.size();
        
        vector<pair<int, int>> meetings;
        for(int i=0;i<n;i++) {
            meetings.push_back(make_pair(start[i], end[i]));
        }
        
        sort(meetings.begin(), meetings.end(), [](const auto& a, const auto& b) {
            return a.second < b.second;
        });
        
        int meetCount = 1;
        int prevEnd = meetings[0].second;
        
        for(int i=1;i<n;i++) {
            if(meetings[i].first > prevEnd) {
                meetCount++;
                prevEnd = meetings[i].second;
            }
        }
        
        return meetCount;
    }
};