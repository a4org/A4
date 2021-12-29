/* 
 * LeetCode 116 Populating Next Right Pointers in Each Node
 * Medium
 * Jiawei Wang
 * 2021.12.29
 */

#include <deque>

using namespace::std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        // BFS intuitive
	deque<Node*> cqn;  // current queue layer
	deque<Node*> nqn;  // next queue layer

	nqn.push_back(root);

	while (!nqn.empty()) {
	    cqn = nqn;

	    Node* fst = nqn.front();
	    if (fst == nullptr) break;
	    nqn.pop_front(); // the first node, cannot use in distribute next

	    for (int i = 0; i < cqn.size()-1; i++) {
		// except last
		Node* node = cqn[i];
		// next layer
		nqn.push_back(node->left);
		nqn.push_back(node->right);

		node->next = nqn.front();
		nqn.pop_front();
	    }

	    Node* last = cqn[cqn.size()-1];
	    nqn.push_back(last->left);
	    nqn.push_back(last->right);
	    last->next = nullptr;
	}

	return root;
    }
};
