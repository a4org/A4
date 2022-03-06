#include <vector>
#include <unordered_map>

using namespace::std;

class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        unordered_map<int, int> countm = {};
        for (int i = 0; i < nums.size()-1; i++) {
            if (nums[i] == key) {
                countm[nums[i+1]]++;
            }
        }
        
        int ret = INT_MIN;
        int MAX = INT_MIN;
        
        for (auto p : countm) {
            if (p.second > MAX) {
                MAX = p.second;
                ret = p.first;
            }
        }
        return ret;
        
    }
};
