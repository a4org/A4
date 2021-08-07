/* 
 * LeetCode 127 Word Ladder
 * Hard
 * Jiawei Wang
 * 2021.8.7
 */

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace::std;


class Solution {
public:
    // #1 BFS (Understand) (Correct but TLE)
    int ladderLength1(string beginWord, string endWord, vector<string>& wordList) {
	// #1 Build a hash table
	// which key is the index, the value is a vector of indices 
	// which diffs by a single letter of this value of index
	
	unordered_map<int, unordered_set<int>> graph;
	wordList.insert(wordList.cbegin(), beginWord);

	auto sz = wordList.size();
	auto len = beginWord.length();
	unordered_map<string, int> index;

	for (int i = 0; i < sz; i++) 
	    index[wordList[i]] = i;

	if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0; // endWord not in wordList
	int target = index[endWord];

	for (int i = 0; i < sz; i++) {
	    string word = wordList[i];
	    for (int j = 0; j < len; j++) {
		for (int c = 0; c < 26; c++) {
		    char ch = c+97;
		    string newword = word.substr(0, j) + ch + word.substr(j+1, len);

		    if (find(wordList.cbegin(), wordList.cend(), newword) != wordList.cend() && newword != word) {
			// there have two words diffs by a single letter
			graph[i].insert(index[newword]);
			graph[index[newword]].insert(i);
		    }
		}
	    }
	}


	// #2 Do BFS, and try to find the shortest word ladder
	
	queue<int> stk; // different layer unfinished
	vector<int> level (sz, -1);
	level[0] = 0;
	stk.push(0);

	while (!stk.empty()) {
	    int curr = stk.front();
	    stk.pop();
	    for (auto i : graph[curr]) {
		// this level
		if (level[i] == -1) {
		    level[i] = level[curr] + 1;
		    if (i == target) 
			return level[i] + 1;
		    stk.push(i);
		}
	    }
	}

	return 0;
    }

    // #2 BFS
    int ladderLength2(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());        
        if (!dict.count(endWord)) return 0;
        
        queue<string> q;
        q.push(beginWord);
        
        int l = beginWord.length();
        int step = 0;
        
        while (!q.empty()) {
            ++step;
            for (int size = q.size(); size > 0; size--) {                
                string w = q.front();                
                q.pop();
                for (int i = 0; i < l; i++) {                
                    char ch = w[i];
                    for (int j = 'a'; j <= 'z'; j++) {
                        w[i] = j;
                        // Found the solution
                        if (w == endWord) return step + 1;
                        // Not in dict, skip it
                        if (!dict.count(w)) continue;
                        // Remove new word from dict
                        dict.erase(w);
                        // Add new word into queue
                        q.push(w);                    
                    }
                    w[i] = ch;
                }
            }
        }
        return 0;
    }

    // 3. Bidirectional BFS
    int ladderLength3(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());        
        if (!dict.count(endWord)) return 0;
        
        int l = beginWord.length();
        
        unordered_set<string> q1{beginWord};
        unordered_set<string> q2{endWord};
                
        int step = 0;
        
        while (!q1.empty() && !q2.empty()) {
            ++step;
            
            // Always expend the smaller queue first (balance)
            if (q1.size() > q2.size())
                swap(q1, q2);
                        
            unordered_set<string> q;
            
            for (string w : q1) {
                for (int i = 0; i < l; i++) {
                    char ch = w[i];
                    for (int j = 'a'; j <= 'z'; j++) {
                        w[i] = j;
                        if (q2.count(w)) return step + 1;
                        if (!dict.count(w)) continue;                        
                        dict.erase(w);
                        q.insert(w);
                    }
                    w[i] = ch;
                }
            }
            
            std::swap(q, q1);
        }
        
        return 0;
    }
};







