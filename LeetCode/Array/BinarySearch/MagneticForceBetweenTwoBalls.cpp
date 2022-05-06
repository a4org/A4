/* 
 * LeetCode 1552 Magnetic Force Between Two Balls
 * Medium
 * Jiawei Wang
 * 2022.4.22
 */

/* Revision
 * $1 2022.5.6 Jiawei Wang
 */

#include <vector>
#include <algorithm>

using namespace::std;

class Solution {
public:
  int maxDistance(vector<int>& position, int m) {
    // guess the solution, using binary search
    sort(position.begin(), position.end());
    int start = 0, end = position.back() - position.front();
    while (start < end) {
      // binary search
      int guess = end - (end - start)/2;
      if (helper(guess, position, m)) {
	start = guess;
      } else {
	end = guess - 1;
      }
    }
    return start;
  }
private:
    bool helper(int guess, vector<int>& position, int m) {
      // check whether it is a valid guess
      int count = 1;
      for (int i = 0; i < position.size();) {
	// greedy -> the first ball must in position[0]
	int j = i;
	while (j < position.size() && position[j] - position[i] < guess) {
	  j++;
	}
	if (j == position.size())
	  break;
	else {
	  // find one
	  count++;
	  i = j;
	}
	if (count == m) return true;
      }
      return false;
    }
};
