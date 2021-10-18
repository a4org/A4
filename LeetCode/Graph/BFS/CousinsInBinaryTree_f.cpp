/*
 * LeetCode 993 Cousins In Binary Tree
 * Easy
 * Shuo Feng
 * 2021.10.18
 */

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
 * Solution 1: Bfs
 *   General idea: record and compare their parents.
 */

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
      
        // Storage node and their parents.
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({ root, nullptr });

        while (!q.empty()) {
            int size = q.size();
          
            // Record x and y in each level.
            vector<TreeNode*> parents;

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front().first;
                TreeNode* father = q.front().second;
                q.pop();

                if (node->val == x || node->val == y)
                    parents.push_back(father);

                if (node->left != nullptr) {
                    q.push({ node->left , node });
                }
                if (node->right != nullptr) {
                    q.push({ node->right, node });
                }
            }
            // size = 0, both x and y dose not exist.
            // size = 1, x and y does not exist in a same level.
            // size = 2, there is possibility that x and y are cousins
            if (parents.size() == 0) continue;
            else if (parents.size() == 1) return false;
            else if (parents.size() == 2) {
                if (parents[0] == parents[1]) return false;
                else return true;
            }

        }
        return false;
    }
};

/*
 * Solution 2: Dfs
 */

class Solution {
private:
    int depth_x = 0;  // Depth of x / y
    int depth_y = 0;
    TreeNode* father_x = nullptr;  // Parent of x / y
    TreeNode* father_y = nullptr;
    void dfs(TreeNode* node, int x, int y, TreeNode* father, int level) {
        if (node == nullptr) return;

        if (node->val == x) {
            depth_x = level;
            father_x = father;
        }

        if (node->val == y) {
            depth_y = level;
            father_y = father;
        }

        dfs(node->left, x, y, node, level + 1);
        dfs(node->right, x, y, node, level + 1);
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, x, y, nullptr, 0);
        return (depth_y == depth_x && (father_x != father_y));
    }
};
