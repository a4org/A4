/*
 * LeetCode 3.Longest Substring without Repeating Characters
 * medium
 * Jiawei Wang
 * 2021 8.4
 */


/* #1 Brute Force
 * For each starting index i, find the longest substring.
 *
 *
 * #2 Hash (Sliding Window)
 * -------------------------
 * | a | b | b | c | d | b |
 * -------------------------
 *               i       j
 *
 * Use a hashtable to store the last indies of each characters
 * Keep track the valid starting point, this point should be unique among all the points from i to j
 */

#include <string>
#include <vector>

using namespace::std;

class Solution {
public:

    // #1 Brute Force
    int lengthOfLongestSubstring1(string s) {
	const int n = s.length();
	int ans = 0;
	for (int i = 0; i < n; ++i) { // for each starting index i
	    vector<int> seen(128);
	    int j = i;
	    while (j < n && !seen[s[j]])
		// get the longest substring
		seen[s[j++]]++; // update the j
	    ans = max(ans, j - i); // get the maximum length from current i
	}
	return ans;

    }


    // #2 Hash
    int lengthOfLongestSubstring2(string s) {
	const int n = s.length();
	int ans = 0;
	vector<int> idx(128, -1); // ascii
	for (int i = 0, j = 0; j < n; ++j) { 
	    // search a window (i, j)
	    i = max(i, idx[s[j]] + 1); // i always the maximum non-repeating index
	    // notice that the maximum length before i is store at ans
	    ans = max(ans, j - i + 1); // get the current ans
	    idx[s[j]] = j;  // update the last indies of current character
	}
	return ans; 
    }
};

