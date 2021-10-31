/*
 * LeetCode 2054 Two Best Non-Overlapping Events
 * Medium
 * 2021.10.31
 * Jiawei Wang
 */

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int maxDay = 0;
        // Dynamic Programming
        
        unordered_map<int, vector<int>> endDay; // end Day with its value
        unordered_map<int, vector<int>> begDay; // begin Day with its value
        set<int> days;
        
        for (auto event : events) {
            if (event[1] > maxDay) maxDay = event[1];
            endDay[event[1]].push_back(event[2]);
            begDay[event[0]].push_back(event[2]);
            
            days.insert(event[1]);
            days.insert(event[0]);
        }
        int ret = 0;
        
        // Start
        int fee = 0; // first event end
        int seb = 0; // second event begin
        for (auto i : days) {
            int prefee = fee;
            int preseb = seb;
            for (int value : endDay[i]) {
                // first event end today
                fee = max(fee, value);
            }
            
            fee = max(prefee, fee); // do nothing
            
            for (int value : begDay[i]) {
                // second event start today
                seb = max(prefee + value, seb);
            }
            ret = max(ret, max(seb, fee));
        }
        return ret;
    }
};
