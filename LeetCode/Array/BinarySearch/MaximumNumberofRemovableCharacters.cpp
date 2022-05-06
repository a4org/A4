/* 
 * LeetCode 1898 Maximum Number of Removable Characters
 * Medium
 * Jiawei Wang
 * 2022.4.20
 */

#include <vector>
#include <unordered_map>

using namespace::std;

// Consider using binary search:
// When sequencial and increasing / decreasing monotonictly

class Solution {
public:
  int maximumRemovals(string s, string p, vector<int>& removable) {
    // #1 Generate the pos hash map (for quick access)
    for (int t = 0; t < removable.size(); t++) {
      pos[removable[t]] = t; // t-th time remove removable[t] (for quick access)
    }

    // #2 Binary Search
    int left = 0, right = removable.size();
    while (left < right) {
      int k = right - (right - left)/2; // mid left
      if (helper(s, p, k)) {
	// k-th is a valid removable character
	left = k;
      } else {
	right = k - 1;
      }
    }
    return left;
  }

private:
  unordered_map<int, int> pos;
  // double pointer
  bool helper(string& s, string& p, int k) {
    // check whether k-th is a removable character in s
    // after removing k-th, p is still a subsequence of s
    int i = 0, j = 0; // i -> s index; j -> p index

    while (j < p.size()) {
      // char by char
      // we want delete p[j]
      while (i < s.size() && s[i] != p[j]) {
	i++;
      }

      if (i == s.size()) break; // scan the whole string s
      if (pos.find(i) == pos.end() || pos[i] >= k) {
	// 1. if we will never have chance to remove i, then still valid
	// 2. otherwise, we need to make sure that 
	// at that time (k), we do not move i already
	j++;
      }
      i++;
    }
    return (j == p.size());
  }
};
