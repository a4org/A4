/* 
 * LeetCode 207 Course Schedule
 * Medium
 * Jiawei Wang
 * 2021.8.5
 *
 */

/* #1 Topological Sort
 *
 * We use DFS to deal with each vertax
 * Any moments can only have one vertax in "visited". 
 *
 */
#include <vector>
#include <unordered_map>

using namespace::std;

class Solution {
public:
    unordered_map<int, vector<int>> graph;

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
	for (auto pre : prerequisites) 
	    graph[pre[1]].push_back(pre[0]);

	vector<int> visited(numCourses);

	for (int i = 0; i < numCourses; i++) {
	    if (visited[i] == 0) {
		if (dfs(i, visited)) 
		    // Here comes a "ircle" means we cannot complete topological sort
		    return false;
	    }
	}
	return true;
    }

    bool dfs(int curr, vector<int>& visited) {
	if (visited[curr] == 1) {
	    // there comes a "circle"
	    return true;
	} else if (visited[curr] == 2) {
	    // this vertax has no unvisited neighbor so it becomes finished
	    return false;
	} 

	visited[curr] = 1; // mark it as visited (current deal with)
	for (int ver : this->graph[curr]) {
	    // graph[curr] contains the child of curr (the cources after curr)
	    if (this->dfs(ver, visited)) {
		// if is visited then return true (circle)
		return true;
	    }
	}

	visited[curr] = 2; // mark it as finishee
	return false;
    }
};
