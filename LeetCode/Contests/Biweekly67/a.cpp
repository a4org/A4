#include <vector>
#include <algorithm>

using namespace::std;

// ordering

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
	int n = nums.size();
	vector<int> ret = {};
	vector<int> snums = nums;
	vector<int> knums;
	if (nums.size() == k) return nums;

	sort(snums.begin(), snums.end());
	for (auto rit = snums.rbegin(); rit != snums.rbegin()+k; rit++) {
	    knums.push_back(*rit);
	}

	for (int i = 0; i < n; i++) {
	    for (auto it = knums.begin(); it < knums.end(); it++) {
		if (nums[i] == *it) {
		    ret.push_back(nums[i]);
		    knums.erase(it);
		    break;
		}
	    }
	}
	return ret;
    };
};
