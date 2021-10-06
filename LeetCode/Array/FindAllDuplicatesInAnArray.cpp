/*
 * LeetCode 442 Find All Duplicates in an Array
 * Medium
 * Jiawei Wang
 * 2021 10.6
 */

#include <vector>

using namespace::std;

class Solution {
public:
    // #1 O(nlogn) sorting 
    vector<int> findDuplicates(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1]) ans.push_back(nums[i]);
        }
        return ans;
    }


    // #2 Indexing Sort O(n)
    // n numbers from i to n
    vector<int> findDuplicates2(vector<int>& nums) {
	int n = nums.size();
	nums.insert(nums.begin(), 0);
	for (int i = 1; i <= n; i++) {
	    while(nums[i] != i && nums[i] != nums[nums[i]]) {
		// We aim to make all nums[i] == i
		// if the swap destination nums[nums[i]] is already same as nums[i]
		// means we do not need to swap at this index
		swap(nums[i], nums[nums[i]]);
	    }
	}

	vector<int> ans;

	for (int i = 1; i <= n; i++) {
	    if (nums[i] != i) ans.push_back(nums[i]);
	}

	return ans;
    }
};


