/*
 * LeetCode 1186 Maximum Subarray with One Delection
 * Medium
 * Jiawei Wang
 * 2021 8.15
 */

/*
 * Dynamic Programming
 *
 * In each step, from 0 to n we only have these 3 cases:
 * 1. suf_del: means we delete one element (i), and the ans now become sufficient large
 * means last step we must in suf_no_del
 * suf_del = max(suf_del + a[i], suf_no_del)
 *
 * 2. suf_no_del: means we do not choose to delete the ith element just keep adding value
 * suf_no_del = max(suf_no_del + a[i], a[i])
 *
 * 3. answer: means we already got the answer, in each step we should compare it with other two status
 * answer = max(answer, suf_del, suf_no_del)
 *
 *
 */


#include <vector>

using namespace::std;

class Solution {
public:
    // Dynamic Programming
    int maximumSum(vector<int>& a) {
	const int n = a.size();

	// init
	int answer = a[0];
	int suf_no_del = a[0];
	int suf_del = 0; // delete the first element

	for (int i = 1; i < n; ++i) {
	    suf_del = max(suf_del + a[i], suf_no_del);
	    suf_no_del = max(suf_no_del + a[i], a[i]);
	    answer = max({answer, suf_del, suf_no_del});
	}
	return answer;
    }

};

