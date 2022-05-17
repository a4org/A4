/*
 * LeetCode 1871 Jump Game VII
 * Medium
 * Jiawei Wang
 * 2022.5.17
 */

#include <string>
#include <vector>

using namespace::std;

class Solution {
public:
  bool canReach(string s, int minJump, int maxJump) {
    if (s.back() == '1') return false;

    int n = s.size();

    vector<int> diff(n+1);

    diff[0+minJump] = 1;
    diff[0+maxJump+1] = -1;

    int reach = 0;
    for (int i = 1; i < n; i++) {
      reach += diff[i];
      if (reach == 0) continue;  // never reach here
      if (s[i] == '1') continue; // can't land here

      if (i+minJump <= n) diff[i+minJump] += 1;
      if (i+maxJump+1 <= n) diff[i+maxJump+1] -= 1;
    }

    return reach; // no need to sort (already as the time being)
  }
};

