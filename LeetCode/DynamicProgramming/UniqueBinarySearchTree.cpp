/*
 * LeetCode 96 Unique Binary Search Tree
 * Medium
 * Shuo Feng
 * 2021.8.17
 * Last edited at 2021.9.16
 */

#include<iostream>
#include<vector>
using namespace std;

/*
 * Solution :Dp
 *   For case " n = 0 ", " n = 1 " we can find the result easily.
 *   If BST include n nodes, to find all BST, only base on all place before n, combine the possible cases of it`s left and right sub-tree.
 *
 *  For example, if n = 4, when set 2 as root node, all possible situation:
 *                                         2
 *                                       /    \
 *                   result of case " n = 1 "  " n = 2 "
 */

class Solution {
public:
    int numTrees(int n) {
        vector<int> nums(1 + n);  // Storage the number of BST about each cases.
        nums[0] = 1;
        nums[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                // Root : i
                nums[i] += nums[j] * nums[i - j - 1];
            }
        }
        return nums[n];
    }
};
