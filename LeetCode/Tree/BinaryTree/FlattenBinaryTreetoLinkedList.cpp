/*
 *LeetCode 114 Flatten Binary Tree To Linked List
 *Medium
 *Shuo Feng
 *2021.7.27
 */

/*
 * Solution 1:
 *summary:
 *   The easies way: collect the results of traversal with a array, and link the nodes in orther.
 *   Better way to linking: 
 *          ╭────╮
 *          │link│-->
 *     o____o____o....o....o....o....o
 *
 *               ╭────╮
 *               │link│-->
 *     o____o____o....o....o....o....o
 *
 *               ╭────╮ 
 *               │link│-->
 *     o____o____o____o....o....o....o      ...
 *                                                                                                                                  ☄
 *   Difficult I have met:
 *     # The passing of pointers
 *
 */

#include<iostream>
#include<vector>
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

class Solution {
public:
    void flatten(TreeNode* root) {
        vector<TreeNode*>list;
        front_traverse(root,list);
        TreeNode *Pre, *Aft;
        for(int i = 1; i< list.size(); ++i){
            Pre = list[i-1];
            Aft = list[i];
            Pre->left = nullptr;
            Pre->right = Aft; 
        }
    }

    void front_traverse(TreeNode* root, vector<TreeNode*>&list){
        if(root != NULL ) {
            list.push_back(root);
            front_traverse(root-> left , list);
            front_traverse(root-> right, list);
        }
    }
};

/*
 * Solution 2:
 *   Each time find the rightmost node("next") of root`s left node, connect root`s right subtree after it(as right subtree),
 *  replace root`s right subtree with left subtree.
 *             1                  1                        1                  1            1
 *            /  \               /                           \                  \            \
 *           2    5             2                             2                  2            2
 *          /  \    \          /  \                          /  \               /               \
 *         3    4    6        3    4                        3    4             3                 3
 *                                   \                             \             \                 \
 *                                    5                             5             4                 4
 *                                      \                             \             \                 \
 *                                       6                             6             5                 5
 *                                                                                     \                 \
 *                                                                                      6                 6
 */

class Solution {
public:
    void flatten(TreeNode* root) {
        while (root != nullptr) {
            if (root->left != nullptr) {
                //root = root-> left;
                TreeNode* next = root->left;
                while (next->right != nullptr) {
                    next = next->right;
                }
                next->right = root->right;
                root->right = root->left;
                root->left = nullptr;
            }
            root = root->right;
        }
    }
};
