#include <stack>
#include <iostream>

using namespace std;

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    int pairSum(ListNode* head) {
	// brute force
	
	ListNode* node = head;
	stack<int> last = {};
	int ret = 0; // all positive

	int count = 0;
	while (node->next) {
	    node = node->next;
	    count++;
	}
	count++;

	int ct = 0;
	node = head;
	while (true) {
	    if (ct >= (count/2)) {
		last.push(node->val);
	    }
	    if (!node->next) break;
	    node = node->next;
	    ct++;
	}

	int indi = 0;
	while (indi != (count/2)) {
	    int val = head->val;
	    ret = max(ret, val+last.top());
	    last.pop();
	    head = head->next;
	    indi++;
	}
	return ret;
    }
};

