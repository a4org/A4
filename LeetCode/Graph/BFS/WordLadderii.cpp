/* 
 * LeetCode 126 Word Ladder ii
 * Hard
 * Jiawei Wang
 * 2021.8.7
 */

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace::std;


class Solution {
public:
    // #1 BFS 
    vector<vector<string>> findLadders1(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> dict(wordList.begin(), wordList.end());        
        if (!dict.count(endWord)) return {};
        dict.erase(beginWord);
        dict.erase(endWord);
        
        unordered_map<string, int> steps{{beginWord, 1}};
        unordered_map<string, vector<string>> parents;
        queue<string> q;
        q.push(beginWord);
        
        vector<vector<string>> ans;
        
        const int l = beginWord.length();
        int step = 0;        
        bool found = false;
        
        while (!q.empty() && !found) {
            ++step;            
            for (int size = q.size(); size > 0; size--) {
                const string p = q.front(); q.pop();
                string w = p;
                for (int i = 0; i < l; i++) {
                    const char ch = w[i];
                    for (int j = 'a'; j <= 'z'; j++) {
                        if (j == ch) continue;
                        w[i] = j;
                        if (w == endWord) {
                            parents[w].push_back(p);
                            found = true;
                        } else {
                            // Not a new word, but another transform
                            // with the same number of steps
                            if (steps.count(w) && step < steps.at(w))
                                parents[w].push_back(p);
                        }
                        
                        if (!dict.count(w)) continue;
                        dict.erase(w);
                        q.push(w);
                        steps[w] = steps.at(p) + 1;
                        parents[w].push_back(p);
                    }
                    w[i] = ch;
                }
            }
        }
        
        if (found) {
            vector<string> curr{endWord};
            getPaths(endWord, beginWord, parents, curr, ans);
        }
    
        return ans;
    }
    // 2. Bidirectional BFS
    vector<vector<string>> findLadders2(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return ans;
        
        int l = beginWord.length();
        
        unordered_set<string> q1{beginWord};
        unordered_set<string> q2{endWord};
        unordered_map<string, vector<string>> children;
 
        bool found = false;
        bool backward = false;
        
        while (!q1.empty() && !q2.empty() && !found) {            
            // Always expend the smaller queue first
            if (q1.size() > q2.size()) {
                std::swap(q1, q2);
                backward = !backward;
            }
            
            for (const string& w : q1)
                dict.erase(w);
            for (const string& w : q2)
                dict.erase(w);
                        
            unordered_set<string> q;
            
            for (const string& word : q1) {
                string curr = word;
                for (int i = 0; i < l; i++) {
                    char ch = curr[i];
                    for (int j = 'a'; j <= 'z'; j++) {
                        curr[i] = j;
                        
                        const string* parent = &word;
                        const string* child = &curr;
                        
                        if (backward)
                            std::swap(parent, child);
                        
                        if (q2.count(curr)) {
                            found = true;
                            children[*parent].push_back(*child);
                        } else if (dict.count(curr) && !found) {
                            q.insert(curr);
                            children[*parent].push_back(*child);
                        }
                    }
                    curr[i] = ch;
                }
            }
            
            std::swap(q, q1);
        }
        
        if (found) {
            vector<string> path{beginWord};
            getPaths(beginWord, endWord, children, path, ans);
        }
        
        return ans;
    }
private:
    void getPaths(const string& word, 
                  const string& beginWord, 
                  const unordered_map<string, vector<string>>& parents,
                  vector<string>& curr,
                  vector<vector<string>>& ans) {        
        
        if (word == beginWord) {
            ans.push_back(vector<string>(curr.rbegin(), curr.rend()));
            return;
        }
        
        for (const string& p : parents.at(word)) {
            curr.push_back(p);
            getPaths(p, beginWord, parents, curr, ans);
            curr.pop_back();
        }        
    }
};
