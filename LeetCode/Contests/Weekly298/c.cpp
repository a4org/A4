#include <string>
#include <cmath>

using namespace::std;

class Solution {
public:
  int longestSubsequence(string s, int k) {
    long long sum = 0;
    long long ret = 0;
    // greedy
    for (int i = 0; i < s.size(); i++) {
      char c = s[s.size() - i - 1];
      if (c == '0') ret++;
      else {
	if (pow(2, i) > 1000000000) continue;
	long long p2 = pow(2, i);
	if (sum + p2 <= k) {
	  sum += p2;
	  ret++;
	}
      }
    }

    return ret;
  }
};
