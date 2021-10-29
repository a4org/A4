/*
 * LeetCode 315 Count of Smaller Numbers After Self
 * Hard
 * 2021.10.17
 * Jiawei Wang
 */

// Divide And Conquer + Merge Sort + Binary Search

#include <vector>
#include <algorithm>

using namespace::std;

class Solution {
    vector<int> counts;
public:
    vector<int> countSmaller(vector<int>& nums) {
	int N = nums.size();
	counts.resize(N);

	if (N == 0) return {};

	vector<int> sortedNums = nums;

	helper(nums, sortedNums, 0, N-1);

	return counts;
    }

private: 
    void helper(vector<int>& nums, vector<int>& sortedNums, int start, int end) {
	if (start == end) return;

	// each part(half) of the vector are sorted, then merge them

	int mid = start + (end - start) / 2; // round down ((int) x / 2 <= (float) x / 2)
	helper(nums, sortedNums, start, mid);
	helper(nums, sortedNums, mid+1, end);

	// nums keeps same, we always change the sortedNums, divide and merge them together
	for (int i = start; i <= mid; i++) {
	    // iter represents the position of nums[i] in [begin, mid] when inserting into sorted vector [mid+1, end]
	    auto iter = lower_bound(sortedNums.begin() + mid + 1, sortedNums.begin() + end + 1, nums[i]); // [mid+1, end+1)
	    // must be sorted then we can use lower_bound to binary search
	    counts[i] += iter - (sortedNums.begin() + mid + 1); // Ranking in [mid+1, end]

	    // inside both intervals [start, mid] [mid+1, end], there counts are updated
	    // We only need to update [start, mid] from [mid+1, end]
	    // This is just like merge sort (merge them together) 
	}

	// sort(sorted.begin()+a, sorted.begin()+b+1); // too long 
	// just need to merge them since both of two vectors are already sorted O(N)
	
	vector<int> temp(end - start + 1); // to store the merged vector from start to end
	int i = start, j = mid+1, p = 0;
	while (i <= mid && j <= end) {
	    if (sortedNums[i] <= sortedNums[j]) {
		temp[p] = sortedNums[i];
		i++;
	    } else {
		temp[p] = sortedNums[j];
		j++;
	    }
	    p++;
	}

	while (i <= mid) {
	    temp[p] = sortedNums[i];
	    i++;
	    p++;
	}

	while (j <= end) {
	    temp[p] = sortedNums[j];
	    j++;
	    p++;
	}

	for (int i = 0; i < end-start+1; i++) {
	    sortedNums[start+i] = temp[i];
	}

    }
};
