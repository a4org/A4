/*
 * LeetCode 1 Two Sum
 * Easy
 * Jiawei Wang
 * 2021.8.25
 */

#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace::std;

class Solution {
public:
    // #1 Brute force
    // Time Complexity: O(n^2)
    vector<int> twoSum1(vector<int>& nums, int target) {
	const int size = nums.size();
	for (int i = 0; i < size; i++) {
	    int n = nums[i];
	    for (int j = i+1; j < size; j++) {
		int m = nums[j];
		if (!(target - n - m)) {
		    return vector<int> {i, j};
		}
	    }
	}
	return {};
    }

    // #2 Using hash
    vector<int> twoSum2(vector<int>& nums, int target) {
	unordered_map<int, int> indies;
	for (int i = 0; i < nums.size(); ++i)
	    indies[nums[i]] = i;
	
	for (int i = 0; i < nums.size(); ++i) {
	    int left = target - nums[i];
	    if (indies.count(left) && indies[left] != i) {
		// aviod repitition
	        return {i, indies[left]};
	    }
	}
	return {};
    }
};

