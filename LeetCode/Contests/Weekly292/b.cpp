#include <vector>

using namespace::std;

// Definition for a binary tree node.
 struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
  int averageOfSubtree(TreeNode* root) {
    // DFS
    ret = 0;
    helper(root);
    return ret;
  }

private:
  int ret;
  pair<int, int> helper(TreeNode* node) {
    // num, sum
    pair<int, int> retpair = make_pair(0, 0);
    if (node == nullptr) return retpair;

    retpair.first = 1;
    retpair.second = node->val;

    pair<int, int> lpair = helper(node->left);
    pair<int, int> rpair = helper(node->right);

    retpair.first += lpair.first + rpair.first;
    retpair.second += lpair.second + rpair.second;

    if (retpair.second / retpair.first == node->val) 
      ret++;

    return retpair;
  }
};
