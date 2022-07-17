#include <vector>

using namespace::std;

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
      vector<int> ct(101, 0); // count
      for (auto n : nums) {
	ct[n]++;
      }

      int nump = 0;
      int ret = 0;

      for (int i = 0; i <= 100; i++) {
	int times = ct[i];

	if (times == 0) continue;

	nump += times / 2;

	if (times % 2 == 1)
	  ret++;
      }

      vector<int> rets = {nump, ret};
      return rets;
    }
};
