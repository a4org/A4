/*
 * LeetCode 23 Merge k Sorted Lists.
 * Hard
 * Shuo Feng
 * 2021.9.4
 */

#include<iostream>
#include<vector>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
 * Solution: Group and merge. 
 *   Group the " lists[] " into a array consists of lists pair, change the question into the merge of two lists.
 *
 *   List:             A         B         C         D         E
 *                     └────┬────┘         │         └────┬────┘
 *                          AB             C              DE
 *                          └──────┬───────┘              │
 *                                 ABC                    DE
 *                                 └──────────┬───────────┘
 *                                            ABCDE
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size = lists.size();
        if (size == 0) return nullptr;
        if (size == 1) return lists[0];

        return Grouping(lists, 0, size - 1);
    }

    // Each time choose two lists merge in a list.
    ListNode* Grouping(vector<ListNode*>& lists, int left, int right) {
        if (left == right) return lists[left]; //

        // Place to split: half the total length add the starting place.
        int mid = (right - left) / 2 + left;

        ListNode* list_1 = Grouping(lists, left, mid);
        ListNode* list_2 = Grouping(lists, mid + 1, right);
        return merge(list_1, list_2);
    }

    // Merge two lists, same as " LeetCode 21 Merge Two Sorted Lists "
    //  ( Angorithm4/ LeetCode/ LinkedList/ MergeTwoSortedList.cpp )
    ListNode* merge(ListNode* list_1, ListNode* list_2) {
        if      (list_1 == NULL) return list_2;
        else if (list_2 == NULL) return list_1;

        else if (list_1->val > list_2->val) {
            list_2->next = merge(list_1, list_2->next);
            return list_2;
        }
        else {
            list_1->next = merge(list_1->next, list_2);
            return list_1;
        }
    }
};
