/*
 * LeetCode 146 LRU Cache
 * Medium
 * Shuo Feng
 * 2022.1.16
 */

#include<iostream>
#include<unordered_map>
using namespace std;

/*
 * Solution: Hash Table, Doubly Linked List.
 */

// Defined Linked List
struct LinkedNode {
    int val;
    int key;
    LinkedNode* prev;
    LinkedNode* next;
    LinkedNode() : key(0), val(0), prev(nullptr), next(nullptr) {}
    LinkedNode(int key, int val) : key(key), val(val), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private: 
    unordered_map<int, struct LinkedNode*> table;
    LinkedNode* head;
    LinkedNode* tail;
    int size;

public:
    LRUCache(int capacity) {
        this->size = capacity;

        // Initialize doubly linked list.
        head = new LinkedNode(0, 0); // Value of head node stand length of linked list.
        tail = new LinkedNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        // Key not exists, return -1.
        if (!table.count(key)) {
            return -1;
        }
        // Key exists, return corresponed value.
        else {
            LinkedNode* node = table[key];
            MovetoHead(node);
            return node->val;
        }
    }

    void put(int key, int value) {
        // Key exists, update value.
        if (table.count(key)) {
            LinkedNode* node = table[key];
            MovetoHead(node);
            node->val = value;
        }
        // Key not exists, creat a new node.
        else {
            LinkedNode* node = new LinkedNode(key, value);
            AddtoHead(node);
            table[key] = node;
            head->val += 1;

            if (head->val > size) {
                LinkedNode* removed = tail->prev;
                RemoveNode(removed);
                table.erase(removed->key);
                delete removed;
                head->val -= 1;
            }
        }
    }

    // Move a node to the head.
    void MovetoHead(LinkedNode* node) {
        RemoveNode(node);
        AddtoHead(node);
    }

    // Add a node to the head.
    void AddtoHead(LinkedNode* node) {
        node->prev = head;
        node->next = head->next;
        head->next = node;
        head->next->next->prev = node;
    }

    // Remove a node from linked list
    void RemoveNode(LinkedNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        //node-> next = nullptr;
        //node-> prev = nullptr;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
