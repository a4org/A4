/* 
 * LeetCode 1231 Divide Chocolate
 * Hard
 * Jiawei Wang
 * 2022.5.6
 */

#include <vector>

using namespace::std;

class Solution {
public:
  // Binary Search
  // Guess the value (MTS)
  // continuously increasing / decreasing
  int maximizeSweetness(vector<int>& sweetness, int k) {
    int left = 0, right = 0;
    for (int s : sweetness) {
      right += s;
    }

    // contiguous

    while (left < right) {
      int mid = right - (right - left) / 2;
      if (helper(mid, sweetness, k)) {
	left = mid;
      } else {
	right = mid - 1;
      }
    }

    return left;
  }

private:
  bool helper(int mts, vector<int>& sn, int k) {
    // check whether we can construct a mts
    int sum = 0;
    int ct = 0;  // groups
    for (int i = 0; i < sn.size(); i++) {
      if (ct >= k+1) {
	return true;
      }
      int val = sn[i];
      sum += val;
      if (sum >= mts) {
	sum = 0;
	ct++;
      }
    }
    return ct >= k+1;
  }
};
