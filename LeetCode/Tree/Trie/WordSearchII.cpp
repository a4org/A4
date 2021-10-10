/*
 * LeetCode 212 Word Search ii
 * Hard
 * Jiawei Wang
 * 2021 10.10
 */

#include <string>
#include <vector>
#include <unordered_set>

using namespace::std;


class Solution {
private:
    class TrieNode {
	public:
	TrieNode* next[26];
	bool isEnd;

	TrieNode() {
	    for (int i = 0; i < 26; i++) {
		next[i] = NULL;
	    }
	    isEnd = false;
	}
    };

    TrieNode* root;
    int m, n;
    bool visited[12][12]; // 1 <= m, n <= 12
    unordered_set<string> rets;
    vector<pair<int, int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    // #1 Trie with DFS
    // #2 please check WordSearchII_2.cpp in the same folder
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
	root = new TrieNode();
	for (auto word : words) {
	    // build a Trie
	    TrieNode* node = root;
	    for (auto ch : word) {
		if (node->next[ch-'a'] == NULL) 
		    node->next[ch-'a'] = new TrieNode();
		node = node->next[ch-'a'];
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

	node = node->next[board[i][j] - 'a'];
	// we want this char
	word.push_back(board[i][j]);

	if (node->isEnd == true) {
	    rets.insert(word);
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
};
