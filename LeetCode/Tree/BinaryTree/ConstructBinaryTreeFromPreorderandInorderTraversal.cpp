/*
 * LeetCode 105 Construct Binary Tree from Preorder and Inorder Traversal 
 * Medium
 * Shuo Feng
 * 2021.9.12
 * Last edited at 2021.10.13
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
 * Solution：Recursion                                                                  ↓root
 *   For " preorder ": [root node , Left subtree node , right subtree node].           [3,  9,  20,  15,  7]
 *                                                                            explain:      left └──right─┘
 *                                                                                          ↓root  
 *   For " inorder"  : [left subtree node , root node , right subtree node].           [9,  3,  15,  20,  7]
 *   Acording to these ↑ relations we can defind the range.                             left     └──right─┘

 *      
 */

class Solution {
private:
    // Use a unordered_map to find the place of each number in inorder traversal.
    unordered_map<int, int> map;
 
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int sizePre = preorder.size();
        int sizeIn  = inorder. size();

        // Creat map.
        for (int i = 0; i < sizeIn; ++i)
            map[inorder[i]] = i;

        return build(0, sizePre - 1, 0, sizeIn - 1, preorder, inorder);
    }
 
    //              
    TreeNode* build(int preLeft, int preRight, int inLeft, int inRight, vector<int>& preorder, vector<int>& inorder) {
        if (preLeft > preRight || inLeft > inRight) return nullptr;
        
        // The first place in preorder is root.
        // Find the place of root in preorder traversal, only by this way we can find it in inorder traversal.
        int preRoot = preLeft;               // The place of root node in preorder.
        int inRoot = map[preorder[preLeft]]; // The place of root node in inorder. Search in map.

        // Creat new node (root).
        TreeNode* root = new TreeNode(preorder[preLeft]);
        
        int left = inRoot - inLeft; // Amount of nodes in left subtree.
                            
                            // Range of left subtree, both " preorder " and " inorder " .                                  
        root->left  = build (preLeft + 1       , preLeft + left, inLeft    , inRoot - 1, preorder, inorder);
                            // Range of right subtree.
        root->right = build (preLeft + left + 1, preRight      , inRoot + 1, inRight   , preorder, inorder);
        return root;
    }
};
