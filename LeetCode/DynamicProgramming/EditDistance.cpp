/*
 * LeetCode 72 Edit Distance
 * Hard
 * Jiawei Wang
 * 2022 8.14
 */

#include <string>
#include <unordered_map>


using namespace::std;

class Solution {
public:
  int minDistance(string word1, string word2) {
    unordered_map<string, int> mem = {};
    return helper(word1, word2, word1.size(), word2.size(), mem);
  }

private:
  int helper(string w1, string w2, int l1, int l2, unordered_map<string, int>& mem) {
    string key = to_string(l1) + ',' + to_string(l2); int ret;
    if (mem.find(key) != mem.end()) {
      return mem[key];
    }

    if (l1 == 0) {
      ret = l2;
    } else if (l2 == 0) {
      ret = l1;
    } else if (w1[l1-1] == w2[l2-1]) {
      ret = helper(w1, w2, l1-1, l2-1, mem);
    } else {
      int sub = 1 + helper(w1, w2, l1-1, l2-1, mem);
      int ins = 1 + helper(w1, w2, l1-1, l2, mem);
      int del = 1 + helper(w1, w2, l1, l2-1, mem);
      ret = min(sub, min(ins, del));
    }
    mem[key] = ret;
    return ret;
  }
};
