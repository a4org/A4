/*
 * LeetCode 106 Construct Binary Tree Form Inorder And Postorder Traversal
 * Medium
 * Shuo Feng
 * 2021.11.21
 */

#include<iostream>
#include<vector>
#include<unordered_map>
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
 * Solution 1: Recursion.
 * Time Limit Exceeded.
 *   Similar to LeetCode 105 Construct Binary Tree from Preorder and Inorder Traversal.
 *   (Reference https://github.com/Angorithm4/Angorithm4/blob/main/LeetCode/Tree/BinaryTree/ConstructBinaryTreeFromPreorderandInorderTraversal.cpp)
 *
 *   Different with preorder, the last element in postorder is the root node.   
 *        
 *                                ↓ Root
 *   Postorder: [9,  15, 7,  20,  3].
 *               left└──right─┘
 *
 *                   ↓ Root
 *   Inorder  : [9,  3,  15, 20,  7].
 *               left    └──right─┘
 */

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int sizeIn = inorder.size();
        int sizePost = postorder.size();

        unordered_map<int, int> map;
        for (int i = 0; i < sizeIn; ++i) {
            map[inorder[i]] = i;
        }

        return build(0, sizePost - 1, 0, sizeIn - 1, postorder, inorder, map);
    }

    // Function: find and return root node in specified range.
    //             (Range of postorder         )(range of inorder       )
    TreeNode* build(int postLeft, int postRight, int inLeft, int inRight, vector<int> postorder, vector<int> inorder, unordered_map<int, int> map) {
        if (postLeft > postRight || inLeft > inRight)
            return nullptr;

        int postRoot = postRight;              // Root`s place in postorder, the last element in postorder is root node.
        int inRoot = map[postorder[postRoot]]; // Find root `s place in inorder, search in map.

        TreeNode* root = new TreeNode(postorder[postRoot]);
        int left = inRoot - inLeft;

        root->left  = build(postLeft       , postLeft + left - 1, inLeft    , inRoot - 1, postorder, inorder, map);
        root->right = build(postLeft + left, postRight - 1      , inRoot + 1, inRight   , postorder, inorder, map);
        return root;
    }
};



/*
 * Solution 1.5: Improve on basis of solution 1
 * Accepted
 *
 *   Since we can find root by check the last element of postorder, another way is traverse postorder from right to left,
 *  construct binary begin with right subtree.
 */

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int sizeIn = inorder.size();
        int sizePost = postorder.size();

        unordered_map<int, int> map;
        for (int i = 0; i < sizeIn; ++i) {
            map[inorder[i]] = i;
        }
        int postRoot = sizePost - 1;
        return build(postRoot, 0, sizeIn - 1, postorder, inorder, map);
    }

    TreeNode* build(int& postRoot, int inLeft, int inRight, vector<int>& postorder, vector<int>& inorder, unordered_map<int, int>& map) {
        if (inLeft > inRight)
            return nullptr;

        TreeNode* root = new TreeNode(postorder[postRoot--]);
        int inRoot = map[root->val];

        // From right to left.
        root->right = build(postRoot, inRoot + 1, inRight   , postorder, inorder, map);
        root->left  = build(postRoot, inLeft    , inRoot - 1, postorder, inorder, map);

        return root;
    }
};
