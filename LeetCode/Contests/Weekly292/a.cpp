#include <string>
#include <iostream>

using namespace::std;

class Solution {
public:
  string largestGoodInteger(string num) {
    int cont = 1;
    char ans = '/';
    if (num.size() == 1 || num.size() == 2) return "";

    for (int i = 1; i < num.size(); i++) {
      if (num[i] == num[i-1]) cont++;
      else {
	if (cont >= 3) {
	  ans = max(ans, num[i-1]);
	}
	cont = 1;
      }
    }

    string ret = "";

    if (cont >= 3 && num.back() > ans) {
      for (int i = 0; i < 3; i++) ret.push_back(num.back());
      return ret;
    }

    if (ans == '/') return "";
    else {
      for (int i = 0; i < 3; i++) ret.push_back(ans);
    }
    return ret;
  }
};
