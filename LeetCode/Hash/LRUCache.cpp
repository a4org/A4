/*
 * LeetCode 146 LRU Cache
 * Medium
 * Jiawei Wang
 * 2021.12.10
 */

#include <unordered_map>

using namespace::std;

struct node {
    // the data structure of LRU
    int key;
    int val;
    struct node *next;
    struct node *prev;
    explicit node(int key, int val) : key(key), val(val), next(this), prev(this) {}
};


class LRUCache {
public:
    LRUCache(int capacity) {
	this->size = capacity;
	this->head = new node(0, 0);
    }
    
    int get(int key) {
	if (tables.find(key) == tables.end()) {
	    // cannot find
	    return -1;
	} else {
	    // 1. remove it first
	    struct node* n = tables[key]; // node current deal with
	    // since it is just a cicle, it won't cause any pointer error
	    n->next->prev = n->prev;
	    n->prev->next = n->next;

	    // 2. reinsert it again
	    n->next = head->next;
	    head->next = n;
	    n->prev = head;
	    n->next->prev = n;
	}
	return tables[key]->val;
    }
    
    void put(int key, int value) {
	if (head->val == size && tables.find(key) == tables.end()) {
	    // not update
	    // sacrifice one 
	    node *victim = head->prev;
	    head->prev = victim->prev;
	    victim->prev->next = head;
	    victim->next = victim->prev = victim;
	    tables.erase(victim->key);
	    head->val--; // size --
	    delete victim;
	} else if (tables.find(key) != tables.end()) {
	    // just update
	    get(key);
	    tables[key]->val = value;
	    return;
	}
	// unpin it
	head->val++;
	node *n = new node(key, value);
	n->next = head->next;
	head->next = n;
	n->prev = head;
	n->next->prev = n;
	tables[key] = n;
    }

private:
    int size;
    struct node *head;
    unordered_map<int, struct node*> tables;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
