#include <string>

using namespace::std;

class Solution {
public:
  int minimumNumbers(int num, int k) {

    if (num == 0) return 0;

    if (num < k) return -1;

    int last = helper(num);

    for (int i = 1; i < 10; i++) {
      if (helper(i * k) == last && i * k <= num) return i;
    }

    return -1;
  }


private:
  int helper(int num) {
    // return its last digit
    string ns = to_string(num);
    return ns.back() - '0';
  }
};
