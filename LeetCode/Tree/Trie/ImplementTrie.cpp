/*
 * LeetCode 208 Implement Trie (Prefix Tree)
 * Medium
 * Jiawei Wang
 * 2021 10.8
 */

/* Trie 
 * There are several other data structures
 * like balanced trees and hash tables, which give us the possibility to search for a word in a dataset of strings.
 * Then why do we need trie? 
 * Although hash table has O(1) time complexity for looking for a key, it is not efficient in the following operations:
 * 1. Finding all keys with a common prefix.
 * 2. Enumerating a dataset of strings in lexicographical order.
 *
 * Another reason why trie outperforms hash table, is that as hash table increases in size, 
 * there are lots of hash collisions and the search time complexity could deteriorate to O(n).
 * Trie could use less space compared to Hash Table when storing many keys with the same prefix.
 * Searching for a key in a balanced tree costs O(mlogn) time complexity. (m is the key length)
 */

#include <string>

using namespace::std;

class Trie {
public:
    // implement with array
    Trie() {}

    void insert(string word) {
        Trie* node = this;
        for (char ch : word) {
            ch -= 'a';
            if (!node->next[ch]) { node->next[ch] = new Trie(); }  
            node = node->next[ch];
        }
        node->isword = true; // the last element (end)
    }

    bool search(string word) {
        Trie* node = this;
        for (char ch : word) {
            ch -= 'a';
            if (!node->next[ch]) { return false; }
            node = node->next[ch];
        }
        return node->isword; 
    }

    bool startsWith(string prefix) {
	// pretty like search
        Trie* node = this;
        for (char ch : prefix) {
            ch -= 'a';
            if (!node->next[ch]) { return false; }
            node = node->next[ch];
        }
        return true;
    }

private:
    Trie* next[26] = {};
    bool isword = false;
};
