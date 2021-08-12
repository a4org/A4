/*
 * LeetCode 5  Longest Palindromic Substring
 * Medium
 * Jiawei Wang
 * 2021 7.21
 */

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;

/* #1 Brute Force
 * Time Limit Exceeded
 * Time Complexity: O(n^3) (n^2 * n)
 * get all substr judge whether they are palindomic respectively
 *
 *
 * #2 String
 * Runtime 32ms, Memory 21.1MB
 * Time Complexity O(n^2)
 * Reduce useless comparesion -- when meet two number that not equal 
 * means that it is not a palindomic str, do not need to keep finding anymore
 * But there are a lot of temporary variables which gives a lot of storige pressure
 *
 *
 * #3 DP
 * Runtime 136ms, Memory 8.1MB
 * Time Complexity: O(n^2)
 * Build a DP table:
 * tablep[i][j] will be false if substring str[i....j] is not palindrome
 *
 */

class Solution {
    bool is_palindrome(string s) {
	string rev = s;
	reverse(rev.begin(), rev.end());
	return s == rev;
    }

public:
    // #1 Brute Force
    string longestPalindrome1(string s) {
	int best_len = 0;
	string best_s = "";
	int n = s.length();
	for (int L = 0; L < n; L++) {
	    for (int R = L; R < n; R++) {
		int len = R - L + 1;
		string subs = s.substr(L, len);
		if (is_palindrome(subs) && len > best_len) {
		    best_len = len;
		    best_s = subs;
		}
	    }
	}
	return best_s;
    }

    int good(int x, string s) {
	// return the index of current "mid" length
	// the Time Complexity is O(n^2)
	// But because we use binary search, we just need to call this function
	// O(logn) times instead of O(n) times in #1
	int n = s.length();
	for (int L = 0; L + x <= n; L++) {
	    if (is_palindrome(s.substr(L, x))) {
		return L;
	    }
	}
	return -1;
    }

    // #1.5 Brute Force Using Binary Search (Time Complexity -> O(n^2logn))
    string longestPalindrome15(string s) {
	int best_len = 0;
	string best_s = "";
	int n = s.length();
	for (int parity : {0, 1}) {
	    int low = 0, high = n;
	    if (low % 2 != parity) low++;
	    if (high % 2 != parity) high--;

	    while (low <= high) {
		// try to find the maximum length
		// using binary search

		int mid = (low + high) / 2;
		if (mid % 2 != parity) {
		    // check again
		    mid++;
		}
		if (mid > high) {
		    break;
		}

		int tmp = good(mid, s); // good return the index of current "mid" length
		if (tmp != -1) {
		    // we find a valid palindrome substring
		    // check if it is longer than best_len (curr)
		    if (mid > best_len) {
			best_len = mid;
			best_s = s.substr(tmp, mid);
		    }
		    // binary search, try to get a bigger size
		    low = mid + 2;
		} else {
		    // in this length we do not have a valid palindrome substr
		    // so we try to shorten the "mid" size
		    high = mid - 2;
		}

	    }
	}
	return best_s;
    }


    // #2 String
    string longestPalindrome2(string s) {
	int best_len = 0;
	string best_s = "";
	int n = s.length();
	// odd
	for (int mid = 0; mid < n; mid++) {
	    for (int x = 0; mid - x >= 0 && mid + x < n; x++) {
		if (s[mid-x] != s[mid+x]) {
		    break;
		}
		int len = 2 * x + 1;
		if (len > best_len) {
		    best_len = len; best_s = s.substr(mid - x, len);
		}
	    }
	}

	// even
	for (int mid = 0; mid < n-1; mid++) {
	    for (int x = 1; mid - x + 1 >= 0 && mid + x < n; x++) {
		if (s[mid-x+1] != s[mid+x]) {
		    break;
		}
		int len = 2 * x;
		if (len > best_len) {
		    best_len = len;
		    best_s = s.substr(mid - x + 1, len);
		}
	    }
	}
	return best_s;
    }

    // #3 DP
    string longestPalindrome3(string str) {
	int n = str.size();
	// tablep[i][j] will be false if substring str[i....j] is not palindrome
	bool table[n][n]; 
	memset(table, 0, sizeof(table));

	int maxLength = 1;

	for (int i = 0; i < n; ++i) {
	    // All substrings of length 1 are palindromes
	    table[i][i] = true;
	}

	int start = 0;
	for (int i = 0; i < n - 1; ++i) {
	    // check for sub-string of length 2
	    if (str[i] == str[i+1]) {
		table[i][i+1] = true;
		start = i;
		maxLength = 2;
	    }
	}

	for (int k = 3; k <= n; ++k) {   // k is length of substring
	    // check for lengths greater than 2
	    for (int i = 0; i < n - k + 1; ++i) {   // i is the starting index
		int j = i + k - 1;  // j is the ending index

		// if str[i+1] to str[j-1] is a palindrome (table[i+1][j-1] == true) and str[i] == str[j]
		// then the sub-string from ith index to jth is a palindrome
		if(table[i+1][j-1] && str[i] == str[j]) {
		    table[i][j] = true;
		    if (k > maxLength) {
			start = i;
			maxLength = k;
		    }
		}
	    }
	}

	string best_s = str.substr(start, maxLength);
	return best_s;
    }
};
