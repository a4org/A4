#include <string>
#include <vector>

using namespace::std;

class Solution {
public:
  string greatestLetter(string s) {
    vector<int> upper(26, 0);
    vector<int> lower(26, 0);

    for (auto c : s) {
      if (c >= 65 && c <= 90) {
	upper[c-65] = -1;
      } else {
	lower[c-97] = -1;
      }
    }

    string ret = "";
    for (int i = 25; i >= 0; i--) {
      if (upper[i] == -1 && lower[i] == -1) {
	ret.push_back(char(i+65));
	return ret;
      }
    }

    return ret;
  }
};
