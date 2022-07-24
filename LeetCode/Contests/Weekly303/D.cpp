#include <vector>

using namespace::std;

class Solution {
public:
  long long countExcellentPairs(vector<int>& nums, int k) {
    long long ret = 0;
    for (int i = 0; i < nums.size(); i++) {
      for (int j = 0; j < nums.size(); j++) {

      }
    }
  }
private:
  int helper(int n)
  {
    int count = 0;
    while (n) {
      count += n & 1;
      n >>= 1;
    }
    return count;
  }
};
