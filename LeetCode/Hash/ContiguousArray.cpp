/*
 * LeetCode 525  Contiguous Array
 * Medium
 * Jiawei Wang
 * 2021 7.19
 */

/* #1 Brute Force
 * Find all Subarrays and get the maximum-contiguous Array
 * Time complexity: O(n^2)
 * Space complexity: O(1) 
 */

/* #2 Hash (using map)
 * Trade space for time !!
 * sum all elements when meet 0 add -1, 1 add 1
 * and make a Map to store all the Sum with its corresponding index
 *
 * The number between two index with the same sum will form a contiguous array
 *
 * 2021.8.5 revision: sum of positions when meet two equals means the numbers between these two positions were Contiguous Array
 * 
 * Time complexity: O(n)
 * Space complexity: O(n)
 */

/* Revision
 * $1 2021.9.1 Jiawei Wang
 * Bidirectional: Maximum length question --> do not just think in one direction
 */

#include <string>
#include <vector>
#include <unordered_map>

using namespace::std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
	int sum = 0;
	// Map sum with position (index)
	unordered_map<int, int> Map;

	Map[0] = -1; 
	// special case
	// since initial is 0, when meet another 0 at index i 
	// means the hole subarray from index 0 to i were contiguous array
	// result = i - Map[0] = i + 1

	int result = 0;
	for (int i = 0; i < nums.size(); i++) {
	    sum += (nums[i] == 1?1:-1);
	    if (Map.find(sum)==Map.end()) {
		// when get the two same sum respectively
		// that means all numbers between these two index formed a contiguous array
		Map[sum] = i;
	    } else {
		// update result
		result = max(result, i - Map[sum]); // i - index means distance (length)
	    }
	}
	return result;
    }
};
