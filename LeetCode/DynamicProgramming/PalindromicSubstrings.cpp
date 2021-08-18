/*
 * LeetCode 674 Palindromic Substrings
 * Medium
 * Jiawei Wang
 * 2021 8.18
 */

#include <vector>
#include <string>

using namespace::std;

class Solution {
public:
    // #1 Brute Force (mid)
    // Time Complexity: O(n^2)
    int countSubstrings1(string s) {
	int count = 0;
	int n = s.size();

	for (int i = 0; i < s.size(); i++) {
	    // odd
	    int len = 0;
	    while (i-len>=0 && i+len<n && s[i-len] == s[i+len]) len++;
	    count += len;


	    // even
	    len = 0;
	    while (i-len>=0 && i+1+len<n&&s[i-len] == s[i+1+len]) len++;
	    count += len;
	}
	return count;
    }


    // #2 Manacher's algoithm
    // Time Complexity: O(n)
    int countSubstrings2(string s) {
	string t = "#";
	for (int i = 0; i < s.size(); i++) 
	    t += s.substr(i, 1) + "#";
    
	int count = 0;

	int n = t.size();
	vector<int> P(n, 0);
	int maxCenter = -1;
	int maxRight = -1;

	for (int i = 0; i < n; i++) {
	    int k; // length
	    if (i <= maxRight) {
		int mirr = 2*maxCenter - i;
		k = min(P[mirr], maxRight-i);
		while (i - k >= 0 && i + k < n && t[i-k] == t[i+k]) k++;
	    } else {
		// caculate k from scrach
		k = 0;
		while (i - k >= 0 && i + k < n && t[i-k] == t[i+k]) k++;
	    }

	    P[i] = k-1;
    
	    if (i + P[i] > maxRight) {
		maxRight = i + P[i];
		maxCenter = i;
	    }
	}

	int ret = 0;
	for (int i = 0; i < n; i++) ret += (P[i]+1) / 2; // p[i] must be an odd number

	return ret;
    }
};



