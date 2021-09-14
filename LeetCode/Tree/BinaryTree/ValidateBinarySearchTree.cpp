/*
 * LeetCode 98 Validate Binary Search Tree
 * Medium
 * Shuo Feng
 * 2021.8.9
 * Second edited at 2021.9.8
 * Last edited at 2021.9.14
 */

#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

 //Definition for a binary tree node.
 struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


/*
 *  Solution 1: Dfs ,Inorder Traversal:
 *   Inorder traverse the binary tree and record value of each nodes in 'list', if it is a valid binary search tree 
 *  the values in 'list' should be sorted from smallest to largest .
 */


class Solution {
public:
    vector<int> list;
    bool isValidBST(TreeNode* root) {
        traverse(root);
     
        // Check whether "list" is a increasing sequence.
        for (int i = 1; i < list.size(); ++i) {
            if (list[i] <= list[i - 1]) return false;  // Binary tree is invalid
        }
        return true;
    }
 
    // Inorder traversal.
    void traverse(TreeNode* root) {
        if (root) {
            traverse(root->left);
            list.push_back(root->val);
            traverse(root->right);
        }
        else return;
    }
};

/*
 * Solution 2: Bfs ,Inorder Traversal
 *   Storage the result of inorder traversal in a stack, compare node with the node before.
 *   
 * Track but not Queue: 
 *   If turn the result of inorder traversal into a array, the node storage first is on the tail of array.
 */

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        //if(root == nullptr) return false;
        stack<TreeNode*> Nodestack;
        TreeNode* Node = root;
        TreeNode* PreNode = nullptr; // Node before 
        
        while (!Nodestack.empty() || Node != nullptr) {
            if (Node != nullptr) {
                Nodestack.push(Node);
                Node = Node->left;  //Left sub-tree.
            }
            else {
                Node = Nodestack.top();
                Nodestack.pop();
                if (PreNode != nullptr && Node->val <= PreNode->val) // Root
                    return false;
                PreNode = Node;  // Update node before.
                Node = Node->right;  // Right sub-tree, two cases: Right sub-tree is NULL, back to root before.
                                     //                            Right sub-tree exists, inorder traverse the right sub tree.
            }
        }
        return true;
    }
};
