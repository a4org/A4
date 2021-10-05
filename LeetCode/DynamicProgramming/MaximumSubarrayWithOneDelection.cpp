/*
 * LeetCode 1186 Maximum Subarray with One Delection
 * Medium
 * Jiawei Wang
 * 2021 8.15
 */

/* Revision:
 * $1 2021.10.5 Jiawei Wang
 *
 */

/*
 * Dynamic Programming
 *
 * In each step, from 0 to n we only have these 3 cases:
 * 1. suf_del: means we delete one element (i), and the ans now become sufficient large
 * means last step we must in suf_no_del or just already delete a element
 * suf_del = max(suf_del + a[i], suf_no_del)
 *
 * 2. suf_no_del: means we do not choose to delete the ith element just keep adding value
 * suf_no_del = max(suf_no_del + a[i], a[i])
 * at this point we use kadane's algorithm 
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
    // #1 Dynamic Programming
    int maximumSum(vector<int>& a) {
	const int n = a.size();

	// init
	int answer = a[0];
	int suf_no_del = a[0];
	int suf_del = 0; // delete the first element

	for (int i = 1; i < n; ++i) {
	    suf_del = max(suf_del + a[i], suf_no_del); // delete curr a[i]
	    suf_no_del = max(suf_no_del + a[i], a[i]); // do not delete a[i]
	    answer = max({answer, suf_del, suf_no_del});
	}
	return answer;
    }


    // #2 More Direct way
    // https://www.youtube.com/watch?v=AxkYOnS-hjs
    int maximumSum2(vector<int>& arr) {
	int highest = INT_MIN;
	int n = arr.size();
	for (int a : arr) {
	    highest = max(highest, a);
	}
	if (highest < 0) {
	    // all negative
	    return highest;
	}

	vector<int> forward(n);
	int currMax = 0;
	for (int i = 0; i < n; i++) {
	    int a = arr[i];
	    currMax = max(currMax + a, a); // kadane's algorithm
	    forward[i] = currMax;
	}

	vector<int> backward(n);
	currMax = 0;
	int bestMax = 0; // this is for a single-value subarray
	for (int i = n-1; i >= 0; i--) {
	    int a = arr[i];
	    currMax = max(currMax + a, a); // kadane's algorithm
	    backward[i] = currMax;
	    bestMax = max(currMax, bestMax);
	}

	int ans = bestMax;
	for (int i = 1; i < n-1; i++) {
	    // without this element
	    ans = max(ans, forward[i-1] + backward[i+1]);
	}

	return ans;
    }
};

