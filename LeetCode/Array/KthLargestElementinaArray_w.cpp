/*
 * LeetCode 217 Kth Largest Element in an Array
 * Medium
 * Jiawei Wang
 * 2021.10.23
 */

#include <queue>
#include <vector>

using namespace::std;

class Solution {
public:
    // #1 using priority queue
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q(nums.begin(), nums.end());
        for (int i = 0; i < k - 1; ++i) {
            q.pop();
        }
        return q.top();
    }

    // #2 using quick sort partition
    int findKthLargest2(vector<int>& nums, int k) {
	int left = 0; int right = nums.size() - 1;

	while (true) {
	    int desc = Partition(nums, left, right);
	    
	    if (desc == k-1) 
		return nums[desc];

	    if (desc < k-1) {
		// nums[pos-1] is too large
		left = desc + 1;
	    } else {
		right = desc - 1;
	    }
	}
    }

private:
    int Partition(vector<int> &A, int p, int q) {
	// [p, i] [i+1, q]
	//  ----------->
	// descending order
	int x = A[p];
	int i = p;
	for (int j = p + 1; j <= q; j++) {
	    if(A[j] >= x) {
		i = i + 1;
		swap(A[i], A[j]);
	    }
	}
	swap(A[p], A[i]);
	return i;
    }
};

