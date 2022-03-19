#include <algorithm>
#include <vector>

using namespace::std;

class Solution {
public:
    bool divideArray(vector<int>& nums) {
	sort(nums.begin(), nums.end());

	int n = 1;
	int prev = nums[0]; // start
	for (int i = 1; i < nums.size(); i++) {
	    if (prev == nums[i]) {
		n += 1;
	    } else {
		if (n % 2 == 0) {
		    // even
		    n = 1;
		    prev = nums[i];
		} else {
		    // odd invalid
		    return false;
		}
	    }
	}

	if (n != 1 && n % 2 == 0) {
	    return true;
	} 
	return false;
    }
};
