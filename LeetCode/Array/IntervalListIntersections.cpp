/*
 * LeetCode 986 Interval List Intersections
 * Medium
 * Shuo Feng
 * 2021.11.24
 */

#include<iostream>
#include<vector>
using namespace std;

/*
 * Solution: Double Pointers.
 *   Compare two interval, the strat point of intersection is the larger one between 'starti' and 'stratj', the end point is
 *  the samller one between 'endi' and 'endj'.
 */

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int size_1 = firstList.size();
        int size_2 = secondList.size();

        if (size_1 == 0 || size_2 == 0)
            return {};

        vector<vector<int>> ans;
        int group1 = 0; // One of interval of firstList.
        int group2 = 0; // One of Interval of secondList.
        while (group1 < size_1 && group2 < size_2) {
          
            int strat = max(firstList[group1][0], secondList[group2][0]);
            int end   = min(firstList[group1][1], secondList[group2][1]);
            // Condition:
            if (strat <= end)
                ans.push_back({ strat, end });

            // Three situation when move interval.
            if      (firstList[group1][1] <  secondList[group2][1])
                group1 += 1;
            else if (firstList[group1][1] >  secondList[group2][1])
                group2 += 1;
            else if (firstList[group1][1] == secondList[group2][1]) {
                group1 += 1;
                group2 += 1;
            }
        }
        return ans;
    }
};
