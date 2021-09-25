/* 
 * LeetCode 208 Course Schedule ii
 * Medium
 * Jiawei Wang
 * 2021.8.5
 *
 */

/*
 * Same as Courses Schedule i
 * Topological Sort
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
 */


#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace::std;

class Solution {
public:
    unordered_map<int, vector<int>> graph;
    vector<int> Stack = {};

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
	for (auto pre : prerequisites) 
	    this->graph[pre[1]].push_back(pre[0]);

	vector<int> visited(numCourses, 0);


	for (int i = 0; i < numCourses; i++) {
	    if (visited[i] == 0) {
		if (dfs(i, visited)) 
		    // Here comes a "circle" means we cannot complete topological sort
		    return {};
	    }
	}
	reverse(Stack.begin(), Stack.end());
	return Stack;

    }

    bool dfs(int curr, vector<int>& visited) {
	if (visited[curr] == 1) {
	    // there comes a "circle"
	    return true;
	} 
	if (visited[curr] == 2) {
	    // this vertax has no unvisited neighbor so it becomes finished
	    return false;
	} 

	visited[curr] = 1; // mark it as visited (current dealing with)
	for (int ver : this->graph[curr]) {
	    // graph[curr] contains the child of curr (the courses after curr)
	    if (this->dfs(ver, visited)) {
		return true;
	    }
	}
	// once there are no reachable courses of curr, means curr is not a premise of any other courses
	this->Stack.push_back(curr);
	visited[curr] = 2; // mark it as finished
	return false;
    }

};
