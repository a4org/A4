/*
 * LeetCode 496 Next Greater Element i
 * Easy
 * Jiawei Wang
 * 2021.10.19
 */

#include <vector>
#include <unordered_map>
#include <stack>

using namespace::std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
	unordered_map<int, int> Map;

	stack<int> Stack;
	// Monotonic Stack: Keep the Stack increasing / decreasing

	for (int x : nums2) {
	    if (Stack.empty()) Stack.push(x);
	    else if (x <= Stack.top()) {
		// Keep the Stack decreasing
		Stack.push(x);
	    }

	    else {
		// 6 5 3 2 1 4
		// 6 5       4
		while (!Stack.empty() && Stack.top() < x) {
		    Map[Stack.top()] = x;
		    Stack.pop();
		}
		Stack.push(x);
	    }

	}

	vector<int> ret;
	for (auto y : nums1) {
	    if (Map.find(y) == Map.end()) ret.push_back(-1);
	    else ret.push_back(Map[y]);
	}

	return ret;
    }

};
