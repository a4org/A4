/*
 * LeetCode 208 Implement Trie (Prefix Tree)
 * Medium
 * Shuo Feng
 * 2021.10.8
 */

#include<iostream>
#include<vector>
using namespace std;

class Trie {
private:
    Trie* next[26];  // Letters after each node. (non empty -> exist)
    bool isend;      // Whether a word is storaged completety.

  public:
    Trie() {
        // Initialization.
        isend = false;
        memset(next, 0, sizeof(next));
    }

    void insert(string word) {
        Trie* Node = this;
        for (char i : word) {
          
            // Null     -> insert.
            // Non null -> move to next place.
            if (Node->next[i - 'a'] == nullptr)
                Node->next[i - 'a'] = new Trie();
            Node = Node->next[i - 'a'];
        }
        Node->isend = true;
    }

    bool search(string word) {
        Trie* Node = this;
        for (char i : word) {
            Node = Node->next[i - 'a'];
          
            // Stop when there is no letter after.
            if (Node == nullptr)
                return false;
        }
        return Node->isend;
    }

    bool startsWith(string prefix) {
        Trie* Node = this;
        for (char i : prefix) {
            Node = Node->next[i - 'a'];
          
            // Similar to 'search', but return 'true' if 'prefix' exist.
            if (Node == nullptr)
                return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
