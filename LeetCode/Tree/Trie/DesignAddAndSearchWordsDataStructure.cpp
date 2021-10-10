/*
 * LeetCode 211 Design Add and Search Words Data Structure
 * Medium
 * Jiawei Wang
 * 2021 10.10
 */

#include <string>

using namespace::std;

class TrieNode {
public:
    bool word;
    TrieNode* children[26];
    TrieNode() {
        word = false;
        memset(children, NULL, sizeof(children));
    }
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node -> children[c - 'a']) {
                node -> children[c - 'a'] = new TrieNode();
            }
            node = node -> children[c - 'a'];
        }
        node -> word = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(word.c_str(), root);
    }
private:
    TrieNode* root = new TrieNode();
    
    bool search(const char* word, TrieNode* node) {
        for (int i = 0; word[i] && node; i++) {
	    // each iteration: we shorten the word so that we can start from 0
	    // key: both word[i] and node also cannot be null
            if (word[i] != '.') {
		// just like 208 search
		// if there do not have any eligible char -> node = null
                node = node -> children[word[i] - 'a'];
            } else {
                TrieNode* tmp = node;
                for (int j = 0; j < 26; j++) {
                    node = tmp -> children[j];
                    if (search(word + i + 1, node)) {
			// new word index = word + i + 1
                        return true;
                    }
                }
            }
        }
        return node && node -> word;
    }
};

