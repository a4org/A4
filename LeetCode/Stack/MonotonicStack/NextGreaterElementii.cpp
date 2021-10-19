/*
 * LeetCode 503 Next Greater Element ii
 * Medium
 * Jiawei Wang
 * 2021.10.19
 */

#include <vector>
#include <stack>

using namespace::std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
	int n = nums.size();
	for (int i = 0; i < n; i++) {
	    // make it a loop (2n size)
	    nums.push_back(nums[i]);
	}

	vector<int> ret(n, -1);
	stack<int> Stack;

	// Monotonic Stack Just like Next Greater Element i
	for (int i = 0; i < nums.size(); i++) {
	    if (Stack.empty()) Stack.push(i);
	    else if (nums[Stack.top()] >= nums[i])  
		// Keep the Stack decreasing
		Stack.push(i);
	    else {
		while (!Stack.empty() && nums[Stack.top()] < nums[i]) {
		    // check every decreasing elements and get their results
		    if (Stack.top() < n) {
			// we only update the result inside index [0, n]
			ret[Stack.top()] = nums[i];
		    }
		    Stack.pop();
		}
		Stack.push(i);
	    }
	}
	return ret;
    }
};


