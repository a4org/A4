/*
 * LeetCode 973 K Closest Points to Origin
 * Medium
 * Jiawei Wang
 * 2021.12.26
 */

#include <unordered_map>
#include <vector>

using namespace::std;
using LL = long long;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<LL> edis; // store all the distance
        unordered_map<LL, vector<int>> udis; // map distance with index
            
        vector<vector<int>> ret; // ret value
        for (vector<int> point : points) {
            // calculate all distance
            edis.push_back(point[0]*point[0] + point[1]*point[1]);
        }
        
        // merge
        for (int i = 0; i < edis.size(); i++) {
            udis[edis[i]].push_back(i);
        }
                      
        sort(edis.begin(), edis.end());
        LL old_dis = -1;
        for (int i = 0; i < k; i++) {
            LL kdis = edis[i]; // got k-th

            if (kdis == old_dis) continue;

            old_dis = kdis;
            vector<int> ans = udis[kdis];

            for (int index : ans) {
                ret.push_back(points[index]);
            }
        }
        return ret;
    }
};

