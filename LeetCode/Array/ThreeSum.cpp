/*
 * LeetCode 15 Three Sum
 * Medium
 * Jiawei Wang
 * 2021.8.25
 */

#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>

using namespace::std;


class Solution {
public:
    // #1 Brute Force 
    // Time Complexity: O(n^3 logn) (TLE)
    vector<vector<int>> threeSum1(vector<int>& nums) {
	// hardest part:  Find all unique triplets
	// Key: make 3 nums: nums[i] < nums[j] < nums[k]
	// by #1 sort the nums - (will not have: (-1, 3, -2) (-1, -2, 3) only have (-2, -1, 3))
	// #2 using set to store ans -- (will only have one (-1, -1, 2) )
	sort(begin(nums), end(nums));
	const int n = nums.size();
	set<vector<int>> ans;

	for (int i = 0; i < n; ++i) 
	    for (int j = i + 1; j < n; ++j) 
	        for (int k = j + 1; k < n; ++k) 
		    if (nums[i] + nums[j] + nums[k] == 0)
			ans.insert({nums[i], nums[j], nums[k]});

	return vector<vector<int>> {begin(ans), end(ans)};
    }

    // #2 Using hash
    // Time Complexity: O(n^2)
    // Space Complexity: O(n)
    vector<vector<int>> threeSum2(vector<int>& nums) {
	sort(begin(nums), end(nums));
	const int n = nums.size();
	unordered_map<int, int> c; // count
	for (int x : nums) ++c[x];
	vector<vector<int>> ans; // we do not use set here  (1)
	for (int i = 0; i < n; ++i) {
	    if (i && nums[i] == nums[i - 1]) continue; // (1)
	    for (int j = i + 1; j < n; ++j) {
		if (j - 1 != i && nums[j] == nums[j - 1]) continue; // (1)
		const int t = 0 - nums[i] - nums[j]; // nums[i] <= nums[j] <= nums[k];
		// find k: k must equal to t so we just search it from the hash table (O(1) time)
		if (t < nums[j]) continue; // we don't want nums[k] < nums[j], which brings repetition
		if (!c.count(t)) continue; // t is in our nums

		if (c[t] >= (1 + (nums[i] == t) + (nums[j] == t)))  // make sure we have enough count (equal)
		    ans.push_back({nums[i], nums[j], t});
	    }
	}
	return ans;
    }

    // #3 Two Pointers
    // Time Complexity O(n^2)
    // Space Complexity O(1)
    vector<vector<int>> threeSum3(vector<int>& nums) {
	sort(begin(nums), end(nums));
	const int n = nums.size();
	vector<vector<int>> ans;
	for (int i = 0; i < n - 2; ++i) {
	    if (nums[i] > 0) break; // we can't have three positive numbers
	    if (i > 0 && nums[i] == nums[i - 1]) continue; // (1)
	    int l = i + 1;
	    int r = n - 1;
	    // move l and r two pointers
	    while (l < r) {
		if (nums[i] + nums[l] + nums[r] == 0) {
		    // get a ans
		    ans.push_back({nums[i], nums[l++], nums[r--]});
		    // avoid repetition
		    while (l < r && nums[l] == nums[l - 1]) ++l;
		    while (l < r && nums[r] == nums[r + 1]) --r;
		} else if (nums[i] + nums[l] + nums[r] < 0)  {
		    // nums[l] + nums[r] < 0 - nums[i] 
		    // too small increase l
		    l++;
		} else {
		    // nums[l] + nums[r] > 0 - nums[i]
		    // too large decrease r
		    r--;
		}
	    }

	}
	return ans;
    }
};
