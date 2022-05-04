/* 
 * LeetCode 1522 Diameter of N-Ary Tree
 * Medium
 * Jiawei Wang
 * 2022.5.4
 */

#include <vector>
#include <algorithm>

using namespace::std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    int diameter(Node* root) {
      helper(root);
      return ret - 1;
    }

private:
    int ret = 0;
    int helper(Node* node) {
      if (node == nullptr) {
	// Termination Condition
	return 0;
      }

      int ans = 0;
      vector<int> child;

      for (int i = 0; i < node->children.size(); i++) {
	// go through all its child
	child.push_back(helper(node->children[i]));
      }

      if (child.size() > 1) {
	sort(child.rbegin(), child.rend());
	ret = max(ret, child[0] + child[1] + 1);
      } else if (child.size() == 1) {
	ret = max(ret, child[0] + 1);
      } else {
	ret = max(ret, 1);
	return 1;
      }

      return child[0]+1;
    }
};
