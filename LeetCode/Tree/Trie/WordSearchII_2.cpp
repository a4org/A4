/*
 * LeetCode 212 Word Search ii
 * Hard
 * Jiawei Wang
 * 2021 10.10
 */

/*
 * Comprehensive
 * Space for Time
 */

#include <string>
#include <vector>
#include <unordered_set>

using namespace::std;

/* 20x time faster version than #1 with just a little optimization
 *
 * check that example:
 * abcdefghijk -> remove this long word after we push_back() it into ans
 * abcd
 * abc
 *
 * so that we don't need go through that path and insert this abcdefghijk into our set over and over again
 *
 * solution: add an attribute "count" to each nodes
 * count of a Trie node represents how many words that use this "prefix word" 
 * if count == 0, then we do not need to explore it anymore
 */

class Solution {
private:
    class TrieNode {
	public:
	TrieNode* next[26];
	bool isEnd;
	int count; // the attr count

	TrieNode() {
	    for (int i = 0; i < 26; i++) {
		next[i] = NULL;
	    }
	    isEnd = false;
	    count = 0; // start with 0
	}
    };

    TrieNode* root; // gloal root
    int m, n;
    bool visited[12][12]; // 1 <= m, n <= 12
    unordered_set<string> rets;
    vector<pair<int, int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
	root = new TrieNode();
	for (auto word : words) {
	    // build a Trie
	    TrieNode* node = root;
	    for (auto ch : word) {
		if (node->next[ch-'a'] == NULL) 
		    node->next[ch-'a'] = new TrieNode();
		node = node->next[ch-'a'];
		node->count++; // every time you build a word, every its node count++
	    }
	    node->isEnd = true;
	}

	m = board.size();
	n = board[0].size();

	// dfs search (just like Word Search i)
	for (int i = 0; i < m; i++) {
	    for (int j = 0; j < n; j++) {
		// for each start point
		TrieNode* node = root; // root is the trie data structure that we built before
		string word;
		visited[i][j] = 1;
		dfs(board, i, j, node, word);
		visited[i][j] = 0;
	    }
	}
	vector<string> ans(rets.begin(), rets.end());
	return ans;
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node, string& word) {
	if (node->next[board[i][j] - 'a'] == NULL) {
	    // Termination Condition
	    return;
	}

	if (node->next[board[i][j] - 'a']->count == 0) return;

	node = node->next[board[i][j] - 'a'];
	// we want this char
	word.push_back(board[i][j]);

	if (node->isEnd == true) {
	    rets.insert(word);
	    remove(root, word); 
	    node->isEnd = false; 
	    /* why need to set isEnd false?
	     * a (after insert it if isEnd of this node still true, next time we will insert it again) 
	     * aa 
	     * aaa 
	     */
	}
	for (int k = 0; k < 4; k++) {
	    // four dirctions
	    int x = i + dir[k].first;
	    int y = j + dir[k].second;
	    if (x < 0 || x >= m || y < 0 || y >= n) continue;
	    if (visited[x][y]) continue;

	    visited[x][y] = 1;
	    dfs(board, x, y, node, word);
	    // backtracking
	    visited[x][y] = 0;
	}
	// backtracking
	word.pop_back();
    }

    void remove(TrieNode* root, string word) {
	TrieNode* node = root;

	for (char c : word) {
	    node = node->next[c-'a'];
	    node->count--;
	}
    }
};
