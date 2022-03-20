#include <vector>

using namespace::std;

class Solution {
public:
    int countHillValley(vector<int>& nums) {
	int ret = 0;
	int pv = nums[0];
	int curr;
	int hvstate = 0; // 0 -> not defined
	// 1 -> hill. 2 -> valley
	
	if (nums.size() == 1) return 0;

	if (nums[0] > nums[1]) hvstate = 2;
	else if (nums[0] < nums[1]) hvstate = 1;

	for (int i = 1; i < nums.size(); i++) {
	    // lookahead
	    curr = nums[i];

	    // has state, means no equal then we add
	    // vally or hill or not defined
	    if (curr < pv) {
		if (hvstate == 1) {
		    // hill
		    ret += 1;
		}
		hvstate = 2;
	    } else if (curr > pv) {
		if (hvstate == 2) {
		    // vally
		    ret += 1;
		}
		hvstate = 1;
	    }

	    pv = curr;
	}
	return ret;
    }
};
