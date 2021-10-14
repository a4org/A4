/*
 * LeetCode 1008 Construct Binary Search Tree From Preorder Traversal
 * Medium
 * Shuo Feng
 * 2021.10.13
 */

#include<iostream>
#include<vector>
#include<algorithm>
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
 * Solution 1:
 *   For each node in binary search tree, number on it`s left are smaller than it and number on it`s right is bigger,
 *  acording to this we can define the range of left and right sub_tree, (1) left : smaller than root, bigger than all possible number.
 *                                                                       (2) right: bigger than root, smaller than all possible number.
 *
 *   For ex:
 *    8         5         1         7          10                 12                       8
 *    ↑root     left: [5, 1, 7]                right: [10, 12]                           /  \
 *    (8)      [5         1         7]        [10                 12]                   5    10
 *              ↑root     left[1]   right[7]   ↑root  left[null]  right[12]           /  \     \
 *                                                                                  1    7     12
 *
 *   (A similarity: LeetCode 105 Construct Binary Tree From Preorder and Inorder Traversal.
 *     In problem 1008 we can also get inorder traversal by sortting preorder, and solve problem in 105`s way.
 *    )
 */ 

class Solution {
private:
    int place = 0;
    TreeNode* FormTree(vector<int>& preorder, int head, int tail) {
        if (place == preorder.size())
            return nullptr;

        int value = preorder[place];
        if (value < head || value > tail)
            return nullptr;

        // The first node is root.
        TreeNode* node = new TreeNode(value);
        place += 1;
      
        // Range from head to value (smaller than value).
        node->left  = FormTree(preorder, head, value);
        // Range from value to tail (bigger  than value).
        node->right = FormTree(preorder, value, tail);

        return node;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return FormTree(preorder, INT_MIN, INT_MAX);
    }
};
