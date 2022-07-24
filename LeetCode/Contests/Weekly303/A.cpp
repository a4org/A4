#include <set>
#include <string>

using namespace::std;

class Solution {
public:
  char repeatedCharacter(string s) {
    set<char> sc = {};
    for (char c : s) {
      if (sc.find(c) == sc.end()) {
	sc.insert(c);
      } else {
	return c;
      }
    }
    return -1;
  }
};
