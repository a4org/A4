/* 
 * LeetCode 207 Course Schedule
 * Medium
 * Jiawei Wang
 * 2021.8.5
 *
 */

/* #1 Topological Sort
 *
 * A Topological Ordering is an ordering of the nodes in a directed graph
 * where for each directed edge from node A to node B, node A appears before node B in the the ordering
 *
 * The Topological Sort algorithm can find a topological ordering in O(V+E) time
 *
 * Note: 
 * 1. Topological ordering are NOT unique
 * 2. Only Directed Acyclic Graph(DAG) has a valid topological ordering (no cycle)
 */

/* Revision
 * $1 2021.9.25 Jiawei Wang
 * Understand the Key:
 * 1.
 * 4 -> 3 -> 5 -> 4
 * if we start from 3, set visited[3] == 1, then when we reach 4, and explore it 
 * we will check its child visited[3] and return true
 *
 * 2.
 * 2 -> 3 -> 5 -> 4 
 * if we start from 3, and visited[3], visited[5], visited[4] will all become finished and set to 2
 * and we do not need to check anymore
 */

#include <vector>
#include <unordered_map>

using namespace::std;

class Solution {
public:
    unordered_map<int, vector<int>> graph;

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
	for (auto pre : prerequisites) 
	    // pre (i, j) j -> i
	    // graph[a] store all valid courses that a can reach
	    graph[pre[1]].push_back(pre[0]);

	vector<int> visited(numCourses);

	for (int i = 0; i < numCourses; i++) {
	    if (visited[i] == 0) {
		if (dfs(i, visited)) 
		    // Here comes a circle" means we cannot complete topological sort
		    return false;
	    }
	}
	return true;
    }

    bool dfs(int curr, vector<int>& visited) {
	if (visited[curr] == 1) {
	    // there comes a "circle"
	    // Key: 
	    // Understand the meaning of visited[curr] = 1
	    return true;
	} else if (visited[curr] == 2) {
	    // Key: 
	    // We have already done with this curr course, do not need to check it again
	    // this vertax has no unvisited neighbor so it becomes finished
	    return false;
	} 

	visited[curr] = 1; // mark it as visited (current deal with)

	for (int ver : this->graph[curr]) {
	    // graph[curr] contains the child of curr (the courses after curr)
	    if (this->dfs(ver, visited)) {
		// if is visited then return true (circle)
		return true;
	    }
	}

	visited[curr] = 2; // mark it as finished
	return false;
    }
};
