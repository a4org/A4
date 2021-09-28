/* 
 * LeetCode 687 Longest Univalue Path
 * Medium
 * Jiawei Wang
 * 2021.8.23
 */

/* Revision
 * $1 2021.9.28 Jiawei Wang
 */

#include <vector>

using namespace::std;

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
    // DFS + DP
    int longestUnivaluePath(TreeNode* root) {
	if (root == nullptr) return 0;
	int ans = 0;
        dfs(root, &ans);
	return ans;
    } 

    int dfs(TreeNode* root, int* ans) {
	if (root == nullptr) return 0;

	int l = dfs(root->left, ans); // longest left
	int r = dfs(root->right, ans); // longest right
	int pl = 0;
	int pr = 0;

	// for each node
	if (root->left && root->val == root->left->val) pl = l + 1;
	if (root->right && root->val == root->right->val) pr = r + 1;

	*ans = max(*ans, pl + pr); // the ans must contain both left and right (just update ans each dfs recursion)
	// ans for the curr node

	// but we can only choose one side to return
	return max(pr, pl);  // but each time we only need to return the longest side
    }
};
