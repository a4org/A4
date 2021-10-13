/*
 * Binary Search Tree
 * Jiawei Wang
 * 2021.10.13
 */

#include <iostream>

using namespace::std;

class BST {
private:
    struct node {
	int data;
	node* left;
	node* right;
    };

    node* root;

    node* makeEmpty(node* t) {
	// make the t root tree empty
	if (t == nullptr) {
	    return nullptr;
	}
	makeEmpty(t->left);
	makeEmpty(t->right);
	delete t;
	return nullptr;
    }

    node* insert(int x, node* t) {
	// insert a node with value x into BST
	// t represents the root of which tree you want to add into
	//
	// must insert to the leaf nodes --> no guaranteed performance (O(log(n) -> O(n))
	if (t == nullptr) {
	    // reach the leaf, add into it then return
	    t = new node;
	    t->data = x;
	    t->left = t->right = nullptr;
	} else if (x < t->data) {
	    t->left = insert(x, t->left);
	}
	else if (x > t->data) {
	    t->right = insert(x, t->right);
	}
	return t;
    }

    node* findMin(node* t) {
	if (t == nullptr) {
	    return nullptr;
	}
	else if (t->left == nullptr) {
	    // reach the low-left corner
	    return t;
	}
	else return findMin(t->left);
    }

    node* findMax(node* t) {
	if (t == nullptr) {
	    return nullptr;
	}
	else if (t->right == nullptr) {
	    // reach the low-right corner
	    return t;
	}
	else return findMax(t->right);
    }

    node* remove(int x, node* t) {
	node* temp;
	// try to get node with value x first
	if (t == nullptr) {
	    // happends when there is no value x node
	    return nullptr;
        }
	else if (x < t->data) {
	    t->left = remove(x, t->left);
	}
	else if (x > t->data) {
	    t->right = remove(x, t->right);
	}
	else if (t->left && t->right) {
	    // x == t->data
	    // #1 but both left and right have value
	    temp = findMin(t->right); // choose the min value of right subtree as t (root)
	    // this value is bigger than left subtree but smaller than any other nodes in the right subtree
	    t->data = temp->data;
	    t->right = remove(t->data, t->right);  // then we remove it from right subtree
	}
	else {
	    // x == t->data 
	    // #2 there is only one of its child node has value or x is the child node
	    // just combine it or delete it directly
	    temp = t;
	    if (t->left == nullptr) {
		t = t->right;
	    }
	    else if (t->right == nullptr) {
		t = t->left;
	    }
	    delete temp;
	}
	return t;
    }

    void inorder(node* t) {
	if (t == nullptr) {
	    return;
	}
	inorder(t->left);
	cout << t->data << " ";
	inorder(t->right);
    }

    node* find(node* t, int x) {
	if (t == nullptr) {
	    return nullptr;
	}
	else if (x < t->data) {
	    return find(t->left, x);
	}
	else if (x > t->data) {
	    return find(t->right, x);
	}
	else 
	    // x == t->data
	    return t;

    }

public:
    // interface

    BST() {
	root = nullptr;
    }

    void insert(int x) {
	root = insert(x, root);
    }

    void remove(int x) {
	root = remove(x, root);
    }

    void display() {
	inorder(root);
	cout << endl;
    }

    node* search(int x) {
	return find(root, x);
    }

};


int main() {
    BST t;
    t.insert(20);
    t.insert(25);
    t.insert(15);
    t.insert(10);
    t.insert(30);
    t.display();
    t.remove(20);
    t.display();
    t.remove(25);
    t.display();
    t.remove(30);
    t.display();
    return 0; 
}
