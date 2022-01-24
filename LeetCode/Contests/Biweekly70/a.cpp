#include <vector>
#include <algorithm>

using namespace::std;

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end(), greater<int>()); // sort dec
        
        int atsize = 0;
        int ret = 0;
        if (cost.size() < 3) {
            for (int i = 0; i < cost.size(); i++) ret += cost[i];
            return ret;
        } else if (cost.size() == 3) return cost[0] + cost[1];

        // greedy
        for (int i = 0; i < cost.size() - 2; i += 3) {
            ret += cost[i];
            ret += cost[i+1];
            atsize = i + 2;
        }
        
        if (atsize < cost.size() - 1) {
            for (int i = atsize+1; i < cost.size(); i++) ret += cost[i];
        }
        return ret;
    }
};
