/*
 * LeetCode 129 Sum Root to Leaf Numbers
 * Medium
 * Shuo Feng
 * 2021.9.13
 */

#include<iostream>
#include<vector>
#include<queue>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
 * Solution 1: Dfs
 *   The better way.
 *   Update the " sum " each times come to the next node, when reach leaf, the " sum " is the total sum of root-to-leaf numbers.
 */

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if (root == nullptr) return 0;
        int sum = 0;
        return dfs(root, sum);
    }
    int dfs(TreeNode* root, int sum) {
        if (root == nullptr) return 0;
        sum *= 10;
        sum += root->val;

        if (!root->left && !root->right)
            return sum;
        // Sum of two path.
        return dfs(root->left, sum) + dfs(root->right, sum);
    }
};

/*
 * Solution 2: Bfs
 *   Similar to soultion 1, add the sum when reach leaf.
 *   Use two queues, one to record the node to check, one to record the sum till each node.
 */

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if (root == nullptr) return 0;
        int sum = 0;

        queue<TreeNode*> NodeQ; // Queue of tree nodes.
        queue<int> ValueQ;      // Queue of sum till each tree nodes.
        NodeQ.push(root);
        ValueQ.push(root->val);

        while (!NodeQ.empty()) {
            int Value = ValueQ.front();
            TreeNode* Node = NodeQ.front();

            NodeQ.pop();  //Remove
            ValueQ.pop();

            // Leaf node.
            if (!Node->left && !Node->right)
                sum += Value;

            if (Node->left != nullptr) {
                NodeQ.push(Node->left);
                ValueQ.push(Value * 10 + Node->left->val);
            }
            if (Node->right != nullptr) {
                NodeQ.push(Node->right);
                ValueQ.push(Value * 10 + Node->right->val);
            }
        }
        return sum;
    }
};
